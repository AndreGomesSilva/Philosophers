/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:38:48 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/21 22:07:40 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void free_forks(t_fork *fork)
{
  if (!fork)
    return ;
  free_forks(fork->next);
  free(fork);
}

void	free_philo(t_philo *philo)
{
  if (!philo)
    return ;
  free_philo(philo->next);
  free(philo);
}

void	free_data(t_data *data)
{
  if (!data)
    return ;
  free_forks(data->forks);  
  free(data);
}

void handle_free(t_data *data, t_philo *philo)
{
  free_data(data);
  free_philo(philo);
}
