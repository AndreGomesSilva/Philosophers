/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:41:22 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/24 18:41:06 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int thinking(t_philo *philo)
{
  if (printf("Time: %u Philo %d is thinking\n",get_time() - philo->data->start_time, philo->id) == -1)
    return (-1);
  return (0);
}
