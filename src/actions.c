/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:49:05 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/11 12:40:22 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int think(t_philo *philo);
bool full_check (t_philo *philo);

int to_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->data->death_check);
	if (philo->data->philo_died == true)
	{
		pthread_mutex_unlock(philo->data->death_check);
		return (1);
	}
	printf("%i %i is sleeping\n",  get_time() - philo->data->start_time, philo->nb);
	pthread_mutex_unlock(philo->data->death_check);
	ft_sleep(philo->data->t_to_sleep);
	return (0);
}
void ft_sleep(int ms)
{
	int cur_time;

	cur_time = get_time();
	while ((get_time() - cur_time) < ms)
	{
		usleep(10);
	}
}

void	*routine(void *param)
{
	t_philo *philos;
	
	philos = (t_philo*)param;
	if (philos->nb % 2 == 0)
		ft_sleep(philos->data->t_to_eat / 2);
	while (is_dead(philos) == 0)
	{
		// printf("philo %i last eaten%i\n", philos->nb, get_time() - philos->last_eaten - philos->data->start_time);
		if (get_forks(philos) == true)
			return (NULL);
		//Change
		if (eat(philos) == true)
			return (NULL);
		if (full_check(philos))
			return (NULL);
		if (to_sleep(philos) == true)
			return (NULL);
		if (think(philos) == true)
			return (NULL);
	}
	return (NULL);
}

bool full_check (t_philo *philo)
{
	pthread_mutex_lock(philo->data->death_check);
	if (philo->data->philo_died == true)
	{
		pthread_mutex_unlock(philo->data->death_check);
		return (1);
	}
	pthread_mutex_unlock(philo->data->full_flag);
	pthread_mutex_unlock(philo->data->death_check);
	return (false);
}
int think(t_philo *philo)
{
	pthread_mutex_lock(philo->data->death_check);
	if (philo->data->philo_died == true)
	{
		pthread_mutex_unlock(philo->data->death_check);
		return (1);
	}
	printf("%i %i is thinking\n",  get_time() - philo->data->start_time, philo->nb);
	pthread_mutex_unlock(philo->data->death_check);
	return (0);
}