/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:01:27 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/21 18:01:58 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_sleep(t_philo *philo)
{
  if (printf("Philo %d is sleeping", philo->id) == -1)
    return (-1);
  if (ft_usleep(philo->data->time_to_sleep) == -1)
    return (-1);
  return (0);
}