/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:42:09 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/21 21:28:45 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	valid_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	if (ft_long_atoi(argv[1]) < MIN_INT || ft_long_atoi(argv[1]) > MAX_INT
		|| ft_long_atoi(argv[2]) < MIN_INT || ft_long_atoi(argv[2]) > MAX_INT
		|| ft_long_atoi(argv[3]) < MIN_INT || ft_long_atoi(argv[3]) > MAX_INT
		|| ft_long_atoi(argv[4]) < MIN_INT || ft_long_atoi(argv[4]) > MAX_INT
		|| (argc == 6 && (ft_long_atoi(argv[5]) < MIN_INT
				|| ft_long_atoi(argv[5]) > MAX_INT)))
		return (FALSE);
	return (TRUE);
}
