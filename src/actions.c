/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:38:27 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/12 12:50:32 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_action(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->write);
	printf("%i %i %s\n",  get_time() - philo->data->start_time, philo->nb, str);
	pthread_mutex_unlock(philo->data->write);
}

int take_fork(t_philo *philo)
{
	if (death_check(philo) == true)
		return (true);
	pthread_mutex_lock(philo->left_fork->mutex);
	print_action(philo, "has taken a fork");
	// Handle one philo
	pthread_mutex_lock(philo->right_fork->mutex);
	print_action(philo, "has taken a fork");
	return (EXIT_SUCCESS);
}

int return_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork->mutex);
	philo->left_fork->is_in_use = false;
	pthread_mutex_unlock(philo->right_fork->mutex);
	philo->right_fork->is_in_use = false;
	return (EXIT_SUCCESS);
}

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
	return_fork(philo);
	pthread_mutex_lock(philo->data->meal_count);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->data->meal_count);
	return (0);
}

int to_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->data->write);
	if (death_check(philo) == true)
	{
		pthread_mutex_unlock(philo->data->write);
		return (true);
	}
	printf("%i %i is sleeping\n",  get_time() - philo->data->start_time, philo->nb);
	pthread_mutex_unlock(philo->data->write);
	ft_sleep(philo->data->t_to_sleep);
	return (0);
}