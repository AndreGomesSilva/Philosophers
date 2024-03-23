/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:40 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/23 19:11:56 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>
#include <unistd.h>

void	print_philo(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp)
	{
		printf("%d \n", tmp->id);
		tmp = tmp->next;
	}
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		printf("%d has taken a left fork %u \n", philo->id, get_time());
		pthread_mutex_lock(philo->right_fork);
		printf("%d has taken a right fork %u \n", philo->id, get_time());
		printf("%d is eating %u \n", philo->id, get_time());
		printf("%d is sleeping %u \n", philo->id, get_time());
		printf("%d is thinking %u \n", philo->id, get_time());
		pthread_mutex_unlock(philo->left_fork);
		printf("%d has put a left fork %u \n", philo->id, get_time());
		pthread_mutex_unlock(philo->right_fork);
		printf("%d has put a right fork %u \n", philo->id, get_time());
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		printf("%d has taken a right fork %u \n", philo->id, get_time());
		pthread_mutex_lock(philo->left_fork);
		printf("%d has taken a left fork %u \n", philo->id, get_time());
		printf("%d is eating %u \n", philo->id, get_time());
		printf("%d is sleeping %u \n", philo->id, get_time());
		printf("%d is thinking %u \n", philo->id, get_time());
    pthread_mutex_unlock(philo->right_fork);
    printf("%d has put a right fork %u \n", philo->id, get_time());
    pthread_mutex_unlock(philo->left_fork);
    printf("%d has put a left fork %u \n", philo->id, get_time());
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
	if (data == NULL || philo == NULL)
		return (1);
	if (valid_arguments(argc, argv) && handle_init(argc, argv, data, philo))
	{
		print_philo(philo);
		start_diner(data, philo);
		printf("Its ok");
	}
	else
	{
		write(2, "Error: Invalid arguments\n", 25);
		return (1);
	}
	handle_free(data, philo);
	return (0);
}
