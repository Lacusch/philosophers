/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:24:41 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/12 15:38:56 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void set_death(t_philo *philo)
{
	pthread_mutex_lock(philo->data->death_check);
	philo->data->philo_died = true;
	pthread_mutex_unlock(philo->data->death_check);
}

void increase_full(t_philo	*philo)
{
	pthread_mutex_lock(philo->data->full_flag);
	philo->data->philo_nb++;
	pthread_mutex_unlock(philo->data->full_flag);
}

void set_status(t_philo *philo, bool status)
{
	pthread_mutex_lock(philo->data->is_eating);
	philo->eating = status;
	pthread_mutex_unlock(philo->data->is_eating);
}

void set_last_eaten(t_philo *philo, int time)
{
	pthread_mutex_lock(philo->data->time_check);
	philo->last_eaten = time;
	pthread_mutex_unlock(philo->data->time_check);
}
//set last eaten variable to last eaten