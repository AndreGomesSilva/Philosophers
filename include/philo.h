/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:20:47 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/27 18:16:57 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define TRUE 1
# define FALSE 0

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t			tr;
	int					id;
	int					dead;
	int					eat_count;
	int					satisfied;
	int					last_meal;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	struct s_supervisor	*supervisor;
	struct s_philo		*next;
	struct s_data		*data;
}						t_philo;

typedef struct s_fork
{
	pthread_mutex_t		*fork;
	struct s_fork		*next;
}						t_fork;

typedef struct s_data
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	unsigned int		start_time;
	struct s_fork		*forks;
	int					nb_meals;
}						t_data;

typedef struct s_supervisor
{
	int					break_execution;
	pthread_mutex_t		print;
	struct s_philo		*philos;
	pthread_t			tr;
}						t_supervisor;

//utils

int						ft_usleep(useconds_t time);
long int				ft_long_atoi(const char *str);

//actions
int						thinking(t_philo *philo);
int						eating(t_philo *philo);
int						sleeping(t_philo *philo);
int						is_dead(t_philo *philo);

int	stop_actions(t_philo *philo); //TODO

//handle_free
void					handle_free(t_data *data, t_supervisor *supervisor);

//timer
unsigned int			get_time_ms(void);
unsigned int			get_time(t_philo *philo);

//dinner
void					set_supervisor(t_supervisor *supervisor);
void					create_philos(t_data *data, t_philo *philo);
t_philo					*add_philo(t_philo *philo, t_data *data);
void					create_forks(t_data *data);
void					set_forks(t_data *data, t_philo *philo);
int						init_data(int argc, char **argv, t_data *data);

//init
int						init_data(int argc, char **argv, t_data *data);
int						handle_init(int argc, char **argv, t_data *data,
							t_supervisor *supervisor);
int						valid_arguments(int argc, char **argv);

#endif
