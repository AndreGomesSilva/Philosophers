/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:40 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/25 18:40:28 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

// void	print_philo(t_philo *philo)
// {
// 	t_philo	*tmp;
//
// 	tmp = philo;
// 	while (tmp)
// 	{
// 		printf("%d \n", tmp->id);
// 		tmp = tmp->next;
// 	}
// }

int	verify_if_philo_die(t_philo *philo)
{
	int	time;

	time = get_time() - philo->data->start_time;
	if (time - philo->last_meal > philo->data->time_to_die)
	{
		printf("Time: %u Philo %d is died\n", time, philo->id);
		philo->dead = 1;
		return (TRUE);
	}
  return (FALSE);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while ((philo->eat_count < philo->data->nb_meals || !philo->data->nb_meals)
		&& !philo->dead)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->left_fork);
			printf("Time: %u Philo: %d has taken a left fork\n", get_time()
					- philo->data->start_time, philo->id);
			pthread_mutex_lock(philo->right_fork);
			printf("Time: %u Philo: %d has taken a right fork\n", get_time()
					- philo->data->start_time, philo->id);
				eating(philo);
			pthread_mutex_unlock(philo->left_fork);
			printf("Time: %u Philo: %d has put a left fork\n", get_time()
					- philo->data->start_time, philo->id);
			pthread_mutex_unlock(philo->right_fork);
			printf("Time: %u Philo: %d has put a right fork\n", get_time()
					- philo->data->start_time, philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->right_fork);
			printf("Time: %u Philo: %d has taken a right fork\n", get_time()
					- philo->data->start_time, philo->id);
			pthread_mutex_lock(philo->left_fork);
			printf("Time: %u Philo: %d has taken a left fork\n", get_time()
					- philo->data->start_time, philo->id);
				eating(philo);
			pthread_mutex_unlock(philo->right_fork);
			printf("Time: %u Philo: %d has put a right fork\n", get_time()
					- philo->data->start_time, philo->id);
			pthread_mutex_unlock(philo->left_fork);
			printf("Time: %u Philo: %d has put a left fork\n", get_time()
					- philo->data->start_time, philo->id);
		}
		if (!philo->dead)
		{
			sleeping(philo);
			thinking(philo);
		}
	}
	return (NULL);
}

void	*monitoring(void *param)
{
  t_supervisor	*supervisor;
  t_philo *philo;

  supervisor = (t_supervisor *)param;
  philo = supervisor->philos;
  while (1)
  {
    if (philo == NULL)
      philo = supervisor->philos;
    if (philo->dead == 1 || philo->eat_count == supervisor->philos->data->nb_meals)
    {
      supervisor->see_dead = 1;
      printf("I SEE DEAD\n");
      return (NULL);
    }
    philo = philo->next;
  }
}

void	start_diner(t_data *data, t_philo *philo, t_supervisor *supervisor)
{
	t_philo	*tmp_philo;
	int		number_philo;

	philo->data = data;
	tmp_philo = philo;
	number_philo = data->nb_philo;
	data->start_time = get_time();
  supervisor->philos = philo;
	while (number_philo-- && tmp_philo != NULL)
	{
		if (pthread_create(&tmp_philo->tr, NULL, &routine, tmp_philo) != 0)
		{
			write(2, "Error: pthread_create failed\n", 30);
			return ;
		}
		tmp_philo = tmp_philo->next;
	}
  pthread_create(&supervisor->tr, NULL, &monitoring, supervisor);
	number_philo = data->nb_philo;
	tmp_philo = philo;
	while (number_philo-- && tmp_philo != NULL)
	{
		if (pthread_join(tmp_philo->tr, NULL) != 0)
		{
			write(2, "Error: pthread_join failed\n", 28);
			return ;
		}
		tmp_philo = tmp_philo->next;
	}
  if (pthread_join(supervisor->tr, NULL) != 0)
  {
    write(2, "Error: pthread_join failed\n", 28);
    return ;
  }
}

int	main(int argc, char **argv)
{
	t_data			*data;
	t_philo			*philo;
  t_supervisor   *supervisor;
  
	philo = (t_philo *)malloc(sizeof(t_philo));
	data = (t_data *)malloc(sizeof(t_data));
  supervisor = (t_supervisor *)malloc(sizeof(t_supervisor));
	if (data == NULL || philo == NULL || supervisor == NULL)
	{
		write(2, "Error: malloc failed\n", 22);
		handle_free(data, philo);
		return (1);
	}
	memset(data, 0, sizeof(t_data));
	memset(philo, 0, sizeof(t_philo));
  memset(supervisor, 0, sizeof(t_supervisor));
	if (valid_arguments(argc, argv) && handle_init(argc, argv, data, philo))
	{
		start_diner(data, philo, supervisor);
		printf("Its ok\n");
	}
	else
	{
		write(2, "Error: Invalid arguments\n", 25);
		handle_free(data, philo);
		return (1);
	}
	handle_free(data, philo);
	return (0);
}
