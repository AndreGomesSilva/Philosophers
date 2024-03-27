/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:40 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 21:36:11 by angomes-         ###   ########.fr       */
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
//

int	stop_actions(t_philo *philo)
{
	int	result;

	result = FALSE;
	pthread_mutex_lock(&philo->supervisor->print);
	if (is_dead(philo) || philo->supervisor->break_execution)
		result = TRUE;
	pthread_mutex_unlock(&philo->supervisor->print);
	return (result);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (!stop_actions(philo) && (!philo->data->nb_meals || philo->eat_count < philo->data->nb_meals))
	{
		if (philo->id % 2 == 0 && !stop_actions(philo))
		{
			pthread_mutex_lock(philo->left_fork);
			if (!stop_actions(philo))
				printf("Time: %u Philo: %d has taken a left fork\n",
						get_time(philo),
						philo->id);
			pthread_mutex_lock(philo->right_fork);
			if (!stop_actions(philo))
				printf("Time: %u Philo: %d has taken a right fork\n",
						get_time(philo),
						philo->id);
			if (!stop_actions(philo))
				eating(philo);
			pthread_mutex_unlock(philo->left_fork);
			if (!stop_actions(philo))
				printf("Time: %u Philo: %d has put a left fork\n",
						get_time(philo),
						philo->id);
			pthread_mutex_unlock(philo->right_fork);
			if (!stop_actions(philo))
				printf("Time: %u Philo: %d has put a right fork\n",
						get_time(philo),
						philo->id);
		}
		else if (!stop_actions(philo))
		{
			pthread_mutex_lock(philo->right_fork);
			if (!stop_actions(philo))
				printf("Time: %u Philo: %d has taken a right fork\n",
						get_time(philo),
						philo->id);
			pthread_mutex_lock(philo->left_fork);
			if (!stop_actions(philo))
			  printf("Time: %u Philo: %d has taken a left fork\n",
					get_time(philo),
					philo->id);
			if (!stop_actions(philo))
				eating(philo);
			pthread_mutex_unlock(philo->right_fork);
			if (!stop_actions(philo))
			  printf("Time: %u Philo: %d has put a right fork\n", get_time(philo),
					philo->id);
			pthread_mutex_unlock(philo->left_fork);
			if (!stop_actions(philo))
			  printf("Time: %u Philo: %d has put a left fork\n", get_time(philo),
					philo->id);
		}
		if (!stop_actions(philo))
			sleeping(philo);
		if (!stop_actions(philo))
			thinking(philo);
	}
	return (NULL);
}

void	*monitoring(void *param)
{
	t_supervisor	*supervisor;
	t_philo			*philo;

	supervisor = (t_supervisor *)param;
	philo = supervisor->philos;
	while (1)
	{
		if (philo == NULL)
			philo = supervisor->philos;
		if (philo->dead || is_dead(philo))
		{
			pthread_mutex_lock(&supervisor->print);
			supervisor->break_execution = TRUE;
			printf("Timer: %u Philo %d is dead\n", get_time(philo), philo->id);
			pthread_mutex_unlock(&supervisor->print);
			return (NULL);
		}
		philo = philo->next;
	}
}

void	start_diner(t_data *data, t_supervisor *supervisor)
{
	t_philo	*tmp_philo;
	int		number_philo;

	tmp_philo = supervisor->philos;
	tmp_philo->data = data;
	number_philo = data->nb_philo;
	data->start_time = get_time_ms();
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
	if (pthread_join(supervisor->tr, NULL) != 0)
	{
		write(2, "Error: pthread_join failed\n", 28);
		return ;
	}
	number_philo = data->nb_philo;
	tmp_philo = supervisor->philos;
	while (number_philo-- && tmp_philo != NULL)
	{
		if (pthread_join(tmp_philo->tr, NULL) != 0)
		{
			write(2, "Error: pthread_join failed\n", 28);
			return ;
		}
		tmp_philo = tmp_philo->next;
	}
}

int	main(int argc, char **argv)
{
	t_data			*data;
	t_supervisor	*supervisor;

	if (valid_arguments(argc, argv))
	{
		supervisor = (t_supervisor *)malloc(sizeof(t_supervisor));
		data = (t_data *)malloc(sizeof(t_data));
		memset(supervisor, 0, sizeof(t_supervisor));
		memset(data, 0, sizeof(t_data));
		if (handle_init(argc, argv, data, supervisor) && supervisor && data)
		{
			start_diner(data, supervisor);
			printf("Its ok\n");
		}
		handle_free(data, supervisor);
	}
	else
	{
		write(2, "Error: Invalid arguments\n", 25);
		return (1);
	}
	return (0);
}
