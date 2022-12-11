/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:56:14 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/11 18:17:40 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_eat(t_philo *philo)
{
	// return in case of death
	pthread_mutex_lock(philo->data->write);
	printf("%i %i is eating\n",  get_time() - philo->data->start_time, philo->nb);
	pthread_mutex_unlock(philo->data->write);

}
int eat(t_philo *philo)
{
	// if (!is_dead(philo))
	// 	return (1);
		// printf("My number is:%i\n", philo->nb);
	pthread_mutex_lock(philo->data->time_check);
	if (death_check(philo) == true)
	{
		pthread_mutex_unlock(philo->data->time_check);
		return (true);
	}
	philo->last_eaten = get_time() - philo->data->start_time;
	pthread_mutex_unlock(philo->data->time_check);
	print_eat(philo);
	ft_sleep(philo->data->t_to_eat);
	give_fork(philo);
	pthread_mutex_lock(philo->data->meal_count);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->data->meal_count);
	return (0);
}