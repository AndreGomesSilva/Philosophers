/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:22:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 15:25:10 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	create_forks(t_data *data)
{
	int		i;
	t_fork	*fork;
	t_fork	*tmp;

	i = 0;
	fork = malloc(sizeof(t_fork));
  memset(fork, 0, sizeof(t_fork));
	data->forks = fork;
	while (i < data->nb_philo)
	{
		fork->fork = malloc(sizeof(pthread_mutex_t));
    memset(fork->fork, 0, sizeof(pthread_mutex_t));
		if (pthread_mutex_init(fork->fork, NULL) != 0)
		{
			write(2, "Error: pthread_mutex_init failed\n", 34);
			return ;
		}
		if (i < data->nb_philo - 1)
		{
			tmp = malloc(sizeof(t_fork));
      memset(tmp, 0, sizeof(t_fork));
			fork->next = tmp;
			fork = fork->next;
		}
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

