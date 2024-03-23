/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:17:07 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/23 19:35:46 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_philo(t_data *data, t_philo *philo)
{
	t_philo	*tmp_philo;
	int		number_philo;

	tmp_philo = philo;
	number_philo = data->nb_philo;
	while (--number_philo && tmp_philo != NULL)
	{
		add_philo(tmp_philo);
		tmp_philo = tmp_philo->next;
	}
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->nb_philo = (int)ft_long_atoi(argv[1]);
	data->time_to_die = (int)ft_long_atoi(argv[2]);
	data->time_to_eat = (int)ft_long_atoi(argv[3]);
	data->time_to_sleep = (int)ft_long_atoi(argv[4]);
	if (argc == 6)
		data->nb_meals = (int)ft_long_atoi(argv[5]);
	else
		data->nb_meals = -1;
	if (data->nb_philo < 1 || data->nb_philo > 200 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0
		|| data->nb_meals < 0)
		return (FALSE);
	return (TRUE);
}

void	create_forks(t_data *data)
{
	int		i;
	t_fork	*fork;
	t_fork	*tmp;

	i = 0;
	fork = malloc(sizeof(t_fork));
	data->forks = fork;
	while (i < data->nb_philo)
	{
		fork->fork = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(fork->fork, NULL) != 0)
		{
			write(2, "Error: pthread_mutex_init failed\n", 34);
			return ;
		}
		if (i < data->nb_philo - 1)
		{
			tmp = malloc(sizeof(t_fork));
			fork->next = tmp;
			fork = fork->next;
		}
		else
			fork->next = NULL;
		i++;
	}
}

void	set_forks(t_data *data, t_philo *philo)
{
	int		i;
	t_philo	*tmp_philo;
	t_fork	*forks;

	i = 0;
	forks = data->forks;
	tmp_philo = philo;
	while (i < data->nb_philo && tmp_philo != NULL && forks != NULL)
	{
		tmp_philo->left_fork = forks->fork;
		if (i == data->nb_philo - 1)
			tmp_philo->right_fork = philo->left_fork;
		else
			tmp_philo->right_fork = forks->next->fork;
		forks = forks->next;
		tmp_philo = tmp_philo->next;
		i++;
	}
}

int	handle_init(int argc, char **argv, t_data *data, t_philo *philo)
{
	if ((!data || !philo))
		return (FALSE);
	if (init_data(argc, argv, data) == FALSE)
		return (FALSE);
	create_forks(data);
	create_philo(data, philo);
	set_forks(data, philo);
	return (TRUE);
}
