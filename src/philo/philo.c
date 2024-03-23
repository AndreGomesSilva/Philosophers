/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:39:33 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/23 19:32:47 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo	*get_last_philo(t_philo *philo)
{
  t_philo *last;

  last = philo;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_philo	*add_philo(t_philo *philo)
{
	t_philo	*new_philo;
	t_philo	*last;

	if (philo == NULL)
		return (NULL);
	new_philo = (t_philo *)malloc(sizeof(t_philo));
	if (new_philo == NULL)
  {
    write(2, "Error: malloc failed\n", 22);
		return (NULL);
  }
	new_philo->next = NULL;
	last = get_last_philo(philo);
	last->next = new_philo;
	new_philo->id = last->id + 1;
	return (philo);
}
