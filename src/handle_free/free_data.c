/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:38:48 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 20:19:54 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_forks(t_fork *fork)
{
  t_fork *tmp;
  t_fork *tmp_next;

  tmp = fork;
  while (tmp)
  {
    tmp_next = tmp->next;
    if (tmp->fork)
    {
      pthread_mutex_destroy(tmp->fork);
      free(tmp->fork);
    }
    free(tmp);
    tmp = tmp_next;
  }
}

void free_supervisor(t_supervisor *supervisor)
{
  pthread_mutex_destroy(&supervisor->print);
  free(supervisor);
}

void	free_philo(t_philo *philo)
{
  t_philo *tmp;
  t_philo *tmp_next;

  tmp = philo;
  while (tmp)
  {
    tmp_next = tmp->next;
    free(tmp);
    tmp = tmp_next;
  }
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_forks(data->forks);
	free(data);
}

void	handle_free(t_data *data, t_supervisor *supervisor)
{
  t_philo *philo;

  philo = supervisor->philos;
  free_supervisor(supervisor);
	free_data(data);
	free_philo(philo);
}
