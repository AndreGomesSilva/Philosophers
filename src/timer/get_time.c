/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:16:09 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 17:48:39 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

unsigned int	get_time_ms(void)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		return (write(2, "Error: gettimeofday failed\n", 29), 0);
	return ((tv.tv_sec * (unsigned int)1000) + (tv.tv_usec / 1000));
}

unsigned int get_time(t_philo *philo)
{
  return (get_time_ms() - philo->data->start_time);
}


