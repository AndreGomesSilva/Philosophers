/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:27:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/25 17:35:30 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int ft_error(char *str, t_data *data, t_philo *philo)
{
  printf("%s\n", str);
  handle_free(data, philo);
  exit (-1);
}

