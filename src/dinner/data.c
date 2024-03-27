/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:10:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 15:18:44 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	init_data(int argc, char **argv, t_data *data)
{
	data->nb_philo = (int)ft_long_atoi(argv[1]);
	data->time_to_die = (int)ft_long_atoi(argv[2]);
	data->time_to_eat = (int)ft_long_atoi(argv[3]);
	data->time_to_sleep = (int)ft_long_atoi(argv[4]);
	if (argc == 6)
		data->nb_meals = (int)ft_long_atoi(argv[5]);
	else
		data->nb_meals = 0;
	if (data->nb_philo < 1 || data->nb_philo > 200 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0
		|| data->nb_meals < 0)
		return (FALSE);
	return (TRUE);
}
