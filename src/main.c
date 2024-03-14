/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:40 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/14 18:48:15 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void *routine(){
//   printf("teste from threads\n");
// }

int main(int argc, char **argv)
{
  t_data *data;

  data = (t_data *)malloc(sizeof(t_data));
  if (data == NULL)
    return (1);
  if (valid_arguments(argc, argv) && init_data(argc, argv, data))
  {
    printf("Its ok");
  }
  else
  {
    write(2, "Error: Invalid arguments\n", 25);
    return (1);
  }
  return (0);
}
