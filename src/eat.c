/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:56:14 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/07 14:00:38 by slaszlo-         ###   ########.fr       */
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
	pthread_mutex_lock(philo->data->time_check);
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