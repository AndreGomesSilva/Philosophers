/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:20:47 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/21 21:30:00 by angomes-         ###   ########.fr       */
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
	pthread_t		tr;
	int				id;
	int				right;
	int				left;
	int				eating;
	int				sleeping;
	int				thinking;
	int				dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct s_data	*data;
}					t_philo;

typedef struct s_fork
{
	pthread_mutex_t	*fork;
	struct s_fork	*next;
}					t_fork;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	struct s_fork	*forks;
	int				nb_meals;
}					t_data;

typedef struct s_supervisor
{
	int				number;
	t_data			*data;
	t_philo			*philo;
	pthread_t		*tr;
}					t_supervisor;

//utils
unsigned int		get_time(void);
int					ft_usleep(useconds_t time);
long int			ft_long_atoi(const char *str);
int					ft_error(char *str, t_data *data, t_philo *philo);

//actions
int					handle_init(int argc, char **argv, t_data *data,
						t_philo *philo);
int					thinking(t_philo *philo);

//handle_free
void				handle_free(t_data *data, t_philo *philo);

//init
void				create_philo(t_data *data, t_philo *philo);

//philo
t_philo				*add_philo(t_philo *philo);

int					valid_arguments(int argc, char **argv);
int					init_data(int argc, char **argv, t_data *data);

#endif
