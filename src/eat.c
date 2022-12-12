/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:56:14 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/12 12:00:32 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int eat(t_philo *philo)
{
	pthread_mutex_lock(philo->data->time_check);
	if (death_check(philo) == true)
	{
		pthread_mutex_unlock(philo->data->time_check);
		return (true);
	}
	philo->last_eaten = get_time() - philo->data->start_time;
	pthread_mutex_unlock(philo->data->time_check);
	print_action(philo, "is eating");
	ft_sleep(philo->data->t_to_eat);
	give_fork(philo);
	pthread_mutex_lock(philo->data->meal_count);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->data->meal_count);
	return (0);
}