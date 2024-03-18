/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:20:47 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/18 20:08:04 by angomes-         ###   ########.fr       */
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
	int				right_fork;
	int				left_fork;
	int				eating;
	int				sleeping;
	int				thinking;
	pthread_mutex_t	fork;
	pthread_mutex_t	*right_forks;
	pthread_mutex_t	*left_forks;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct s_data	*data;
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

// typedef struct supervisor
// {
// 	int				number;
// 	t_data			*data;
// 	t_philo			*philo;
// 	pthread_t		*thread;
// 	sem_t			*forks;
// 	sem_t			*print;
// }					t_supervisor;

//utils
unsigned int		get_time(void);
int					ft_usleep(useconds_t time);
long int			ft_long_atoi(const char *str);
int					ft_error(char *str, t_data *data);

//handle_free
void				free_data(t_data *data);

//philo
t_philo				*add_philo(t_philo *philo);

int					valid_arguments(int argc, char **argv);
int					init_data(int argc, char **argv, t_data *data);
#endif
