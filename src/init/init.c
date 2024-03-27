/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:17:07 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 20:17:51 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	init_philo(t_supervisor *supervisor)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	memset(philo, 0, sizeof(t_philo));
	if (philo)
		supervisor->philos = philo;
	return (TRUE);
}

int	handle_init(int argc, char **argv, t_data *data, t_supervisor *supervisor)
{
	if (!init_philo(supervisor) || !init_data(argc, argv, data))
		return (FALSE);
	create_philos(data, supervisor->philos);
	set_supervisor(supervisor);
	create_forks(data);
	set_forks(data, supervisor->philos);
	return (TRUE);
}
