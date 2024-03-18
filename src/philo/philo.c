/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:39:33 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/18 18:04:53 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo *get_last_philo(t_philo *philo)
{
  if (philo == NULL)
    return (NULL);
  while (philo->next != NULL)
    philo = philo->next;
  return (philo);
}

t_philo *add_philo(t_philo *philo)
{
  t_philo *new_philo;
  t_philo *last;

  if (philo == NULL)
    return (NULL);
  new_philo = (t_philo *)malloc(sizeof(t_philo));
  if (new_philo == NULL)
    return (NULL);
  new_philo->next = NULL;
  last = get_last_philo(philo);
  last->next = new_philo;
  new_philo->prev = last;
  new_philo->id = last->id + 1;
  return (philo);
}
