/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:40 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/10 19:37:18 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo(void *param)
{
  long    *my_id;

  my_id = (long *)param;
  printf("%ld\n", *my_id);
}

int main(int ac, char **av)
{
  (void)ac;
  (void)av;
  pthread_t thread;
  
  if (pthread_create(&thread, NULL, philo, (void *)&thread) != 0)
    return (1);
  
  pthread_exit(NULL); 
  return (0);
}
