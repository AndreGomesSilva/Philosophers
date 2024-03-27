/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:28:57 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 20:28:12 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	set_supervisor(t_supervisor *supervisor)
{
	t_philo	*philo;

	philo = supervisor->philos;
	supervisor->break_execution = FALSE;
	while (philo)
	{
		philo->supervisor = supervisor;
		philo = philo->next;
	}
	pthread_mutex_init(&supervisor->print, NULL);
}
