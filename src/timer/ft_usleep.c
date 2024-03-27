/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:18:04 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 17:07:01 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_usleep(useconds_t time)
{
	unsigned long	start;
	start = get_time_ms();
	while ((get_time_ms() - start) < time)
		usleep(time / 10);
	return(0);
}

