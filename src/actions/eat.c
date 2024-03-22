/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:02:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/21 18:02:35 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	eating(t_philo *philo)
{
  if (printf("Philo %d is eating", philo->id) == -1)
    return (-1);
  if (ft_usleep(philo->data->time_to_eat) == -1)
    return (-1);
  return (0);
}
