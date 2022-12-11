/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:38:47 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/11 18:48:00 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void monitoring(t_philo *philos)
{
	int	i;

	while (!death_check(philos))
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
	}
}

bool is_dead(t_philo *philos)
{
	int last_eaten;

	last_eaten = 0;
	pthread_mutex_lock(philos->data->death_check);
	pthread_mutex_lock(philos->data->time_check);
	last_eaten = get_time() - philos->data->start_time - philos->last_eaten;
	pthread_mutex_unlock(philos->data->time_check);
	if (last_eaten >= philos->data->t_to_die)
	{
		philos->data->philo_died = true;
		philos->is_dead = true;
		pthread_mutex_unlock(philos->data->death_check);
		// printf("died\n");
		pthread_mutex_lock(philos->data->write);
		// printf("Went over deadlock\n");
		printf("%d %d died\n", get_time() - philos->data->start_time, philos->nb);
		pthread_mutex_unlock(philos->data->write);
		// pthread_mutex_unlock(philos->data->death_check);
		return (true);		
	}
	pthread_mutex_unlock(philos->data->death_check);
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

bool death_check(t_philo *philo)
{
	pthread_mutex_lock(philo->data->death_check);
	if (philo->data->philo_died == true)
	{
		pthread_mutex_unlock(philo->data->death_check);
		return (true);
	}
	pthread_mutex_unlock(philo->data->death_check);
	return (false);
}