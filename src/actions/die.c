/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:18:39 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 20:40:01 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	is_dead(t_philo *philo)
{
	int	time;

	time = get_time(philo);
	if (time - philo->last_meal >= philo->data->time_to_die)
	{
		philo->dead = 1;
		return (TRUE);
	}
	return (FALSE);
}
