/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:39:33 by angomes-          #+#    #+#             */
/*   Updated: 2024/03/26 19:27:14 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo	*get_last_philo(t_philo *philo)
{
  t_philo *last;

  last = philo;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_philo	*add_philo(t_philo *philo, t_data *data)
{
	t_philo	*new_philo;
	t_philo	*last;

	if (philo == NULL)
		return (NULL);
	new_philo = (t_philo *)malloc(sizeof(t_philo));
	if (new_philo == NULL)
  {
    write(2, "Error: malloc failed\n", 22);
		return (NULL);
  }
  memset(new_philo, 0, sizeof(t_philo));
  new_philo->data = data;
	last = get_last_philo(philo);
  if (last == NULL)
    return (NULL);
  else
  {
  	last->next = new_philo;
  	new_philo->id = last->id + 1;
  }
	return (philo);
}

void	create_philos(t_data *data, t_philo *philo)
{
	t_philo	*tmp_philo;
	int		number_philo;

	tmp_philo = philo;
  philo->id = 1;
	number_philo = data->nb_philo;
	while (--number_philo && tmp_philo != NULL)
	{
    tmp_philo->data = data;
		if (add_philo(tmp_philo, data) == NULL)
    {
      write(2, "Error: malloc failed\n", 22);
      return ;
    }
		tmp_philo = tmp_philo->next;
	}
}

