/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:40 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/13 01:36:08 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int count = 0;
pthread_mutex_t mutex;

void	*routine()
{
  int i;
  i = 0;
  while (i < 1000000)
  {
    pthread_mutex_lock(&mutex);
    count++;
    pthread_mutex_unlock(&mutex);
    i++;
  }
	return (NULL);
}

int	main(int ac, char **av)
{
  (void)ac;
  (void)av;
	pthread_t	th[5];
  int i;

  i = 0;
  pthread_mutex_init(&mutex, NULL);
  while (i < 5)
  {
    if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
    {
      perror("Error\n");
      return (1);
    }
    printf("Thread %d created\n", i);
    i++;
  }

  i = 0;
  while (i < 5)
  {
    if (pthread_join(th[i], NULL) != 0)
    {
      perror("Error\n");
      return (1);
    }
    printf("Thread %d joined\n", i);
    i++;
  }

  printf("%d\n", count);
  pthread_mutex_destroy(&mutex);
	return (0);
}
