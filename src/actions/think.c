/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:41:22 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/21 18:02:48 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int thinking(t_philo *philo)
{
  if (printf("Philo %d is thinking", philo->id) == -1)
    return (-1);
  return (0);
}
