/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:02:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 21:29:35 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	eating(t_philo *philo)
{
	if (!stop_actions(philo))
	{
		pthread_mutex_lock(&philo->supervisor->print);
		printf("Time: %u Philo %d is eating\n", get_time(philo), philo->id);
		philo->last_meal = get_time_ms();
		philo->eat_count++;
		pthread_mutex_unlock(&philo->supervisor->print);
		ft_usleep(philo->data->time_to_eat);
	}
	return (0);
}
