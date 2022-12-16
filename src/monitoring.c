/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:38:47 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/16 17:34:50 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void monitoring(t_philo *philos)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philos->data->philo_nb)
		{
			if (is_dead(&philos[i]))
				return ;
			i++;
		}
	}
}

bool is_dead(t_philo *philos)
{
	int last_eaten;

	if (check_eating(philos) == true)
		return (false);
	last_eaten = get_time() - philos->data->start_time - get_last_eaten(philos);
	if (last_eaten > philos->data->t_to_die)
	{
		pthread_mutex_lock(philos->data->death_check);
		philos->data->philo_died = true;
		philos->is_dead = true;
		pthread_mutex_unlock(philos->data->death_check);
		print_action(philos, "died");
		return (true);		
	}
	else if (full(philos) == 1)
	{
		set_death(philos);
		return (true);
	}
	return (false);
}

