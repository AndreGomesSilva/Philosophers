/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:40 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/21 22:15:14 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	printf("%d has taken a fork %u \n", philo->id, get_time());
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
		pthread_create(&philo->tr, NULL, &routine, tmp_philo);
		tmp_philo = tmp_philo->next;
		number_philo--;
	}
	number_philo = data->nb_philo;
	tmp_philo = philo;
	while (number_philo && tmp_philo != NULL)
	{
		pthread_join(philo->tr, NULL);
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
	if (data == NULL)
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
