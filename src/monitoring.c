/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:38:47 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/05 15:08:33 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void monitoring(t_philo *philos)
{
	int	i;


	while (philos->data->philo_died == false)
	{
		i = 0;
		while (i < philos->data->philo_nb)
		{
			if (!is_dead(&philos[i]))
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
	pthread_mutex_lock(philos->data->time_check);
	last_eaten = get_time() - philos->data->start_time - philos->last_eaten;
	pthread_mutex_unlock(philos->data->time_check);
	if (last_eaten >= philos->data->t_to_eat)
	{
		pthread_mutex_lock(philos->data->death_check);
		philos->data->philo_died = true;
		pthread_mutex_unlock(philos->data->death_check);
		//print lock
		printf("%d %d died", get_time() - philos->data->start_time, philos->nb);
		//print unlock;
		return (true);		
	}
	return (false);
}