/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:27:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/24 19:32:58 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int ft_error(char *str, t_data *data, t_philo *philo)
{
  printf("%s\n", str);
  handle_free(data, philo);
  return (-1);
}

