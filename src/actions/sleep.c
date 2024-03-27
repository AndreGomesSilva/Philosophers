/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:01:27 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 21:02:56 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <pthread.h>

int	sleeping(t_philo *philo)
{
  pthread_mutex_lock(&philo->supervisor->print);
  printf("Time: %u Philo: %d is sleeping\n", get_time(philo), philo->id);
  pthread_mutex_unlock(&philo->supervisor->print);
  ft_usleep(philo->data->time_to_sleep);
  return (0);
}
