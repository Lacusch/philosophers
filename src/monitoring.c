/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:38:47 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/16 16:04:06 by slaszlo-         ###   ########.fr       */
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
				//lock print??
			i++;
			// if full also break;
		}
		if (full(philos))
		{
			// set_death(philos);
			return ;
		}
	}
}
//rewrite
//if eating return false
bool is_dead(t_philo *philos)
{
	int last_eaten;

	if (check_eating(philos) == true)
		return (false);
	// if (full(philos) == true)
	// 	return (true);
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

/*
 heleens stuf from here
void death_set(t_philo *philo)
{
	pthread_mutex_lock(philo->data->death_lock);
	philo->data->death = true;
	pthread_mutex_unlock(philo->data->death_check);
	return ret;
}
*/

