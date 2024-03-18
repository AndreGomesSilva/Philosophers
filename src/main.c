/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:40 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/18 20:34:11 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(&philo->fork);
	printf("%ld %d has taken a fork\n", (long)get_time(), philo->id);
	pthread_mutex_unlock(&philo->fork);
	return (NULL);
}

void	start_diner(t_data *data, t_philo *philo)
{
	philo->data = data;
	pthread_mutex_init(&philo->fork, NULL);
	while (data->nb_philo && philo != NULL)
	{
		pthread_create(&philo->tr, NULL, &routine, philo);
		philo = philo->next;
		data->nb_philo--;
	}
	pthread_join(philo->tr, NULL);
	pthread_mutex_destroy(&philo->fork);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	if (valid_arguments(argc, argv) && init_data(argc, argv, data))
	{
    add_philo(philo);
		start_diner(data, philo);
		printf("Its ok");
	}
	else
	{
		write(2, "Error: Invalid arguments\n", 25);
		return (1);
	}
	return (0);
}
