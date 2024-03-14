/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:17:07 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/14 17:57:30 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	valid_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	if (ft_long_atoi(argv[1]) < MIN_INT || ft_long_atoi(argv[1]) > MAX_INT
		|| ft_long_atoi(argv[2]) < MIN_INT || ft_long_atoi(argv[2]) > MAX_INT
		|| ft_long_atoi(argv[3]) < MIN_INT || ft_long_atoi(argv[3]) > MAX_INT
		|| ft_long_atoi(argv[4]) < MIN_INT || ft_long_atoi(argv[4]) > MAX_INT
		|| (argc == 6 && (ft_long_atoi(argv[5]) < MIN_INT
				|| ft_long_atoi(argv[5]) > MAX_INT)))
		return (FALSE);
	return (TRUE);
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->nb_philo = (int) ft_long_atoi(argv[1]);
	data->time_to_die = (int)ft_long_atoi(argv[2]);
	data->time_to_eat = (int)ft_long_atoi(argv[3]);
	data->time_to_sleep = (int)ft_long_atoi(argv[4]);
	if (argc == 6)
		data->nb_meals = (int)ft_long_atoi(argv[5]);
	else
		data->nb_meals = -1;
	if (data->nb_philo < 1 || data->nb_philo > 200
		|| data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0
		|| data->nb_meals < 0)
		return (FALSE);
	return (TRUE);
}
