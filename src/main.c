/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:40 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/24 20:08:44 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while ((philo->eat_count < philo->data->nb_meals || !philo->data->nb_meals) && !philo->dead)
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
   		sleeping(philo);
			thinking(philo);
	}

	return (NULL);
}

void	start_diner(t_data *data, t_philo *philo)
{
	t_philo	*tmp_philo;
	int		number_philo;

	philo->data = data;
	tmp_philo = philo;
	number_philo = data->nb_philo;
	data->start_time = get_time();
	while (number_philo && tmp_philo != NULL)
	{
		if (pthread_create(&tmp_philo->tr, NULL, &routine, tmp_philo) != 0)
		{
			write(2, "Error: pthread_create failed\n", 30);
			return ;
		}
		tmp_philo = tmp_philo->next;
		number_philo--;
	}
	number_philo = data->nb_philo;
	tmp_philo = philo;
	while (number_philo && tmp_philo != NULL)
	{
		if (pthread_join(tmp_philo->tr, NULL) != 0)
		{
			write(2, "Error: pthread_join failed\n", 28);
			return ;
		}
		tmp_philo = tmp_philo->next;
		number_philo--;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	data = (t_data *)malloc(sizeof(t_data));
	memset(data, 0, sizeof(t_data));
	memset(philo, 0, sizeof(t_philo));
	if (data == NULL || philo == NULL)
	{
		write(2, "Error: malloc failed\n", 22);
		handle_free(data, philo);
		return (1);
	}
	else if (valid_arguments(argc, argv) && handle_init(argc, argv, data,
			philo))
	{
		start_diner(data, philo);
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
