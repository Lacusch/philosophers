/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:25:18 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/12 13:12:36 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool death_check(t_philo *philo)
{
	bool ret;

	pthread_mutex_lock(philo->data->death_check);
	ret = philo->data-> philo_died;
	pthread_mutex_unlock(philo->data->death_check);
	return (ret);
}

bool full(t_philo *philo)
{
	bool ret;

	pthread_mutex_lock(philo->data->full_flag);
	ret = philo->data->philo_nb == philo->data->full;
	pthread_mutex_unlock(philo->data->full_flag);
	return (ret);
}
int get_last_eaten(t_philo *philo)
{
	int time;
	pthread_mutex_lock(philo->data->time_check);
	time = philo->last_eaten;
	pthread_mutex_unlock(philo->data->time_check);
	return (time);
}
