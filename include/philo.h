/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:20:47 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/14 18:47:36 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define TRUE 1
# define FALSE 0

# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				right_fork;
	int				left_fork;
	int				eating;
	int				sleeping;
	int				thinking;
	struct s_philo	*next;
	struct s_philo	*prev;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				dead;
}					t_data;

int					valid_arguments(int argc, char **argv);
int					init_data(int argc, char **argv, t_data *data);
long int			ft_long_atoi(const char *str);



int	ft_error(char *str);
#endif
