/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:02:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/24 20:14:40 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	eating(t_philo *philo)
{
  int time;

  time = get_time() - philo->data->start_time;
  if (time - philo->last_meal > philo->data->time_to_die)
  {
    printf("Time: %u Philo %d is died\n", time, philo->id);
    philo->dead = 1;
    return (-1);
  }
  if (printf("Time: %u Philo %d is eating\n", time, philo->id) == -1)
    return (-1);
  if (ft_usleep(philo->data->time_to_eat) == -1)
    return (-1);
  philo->last_meal = get_time();
  if (philo->data->nb_meals > 0)
    philo->eat_count++;
  return (0);
}
