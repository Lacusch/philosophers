/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:49:05 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/09 15:09:12 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int think(t_philo *philo);
bool full_check (t_philo *philo);

int to_sleep(t_philo *philo)
{
	if (death_check(philo) == true)
		return (true);
	pthread_mutex_lock(philo->data->write);
	printf("%i %i is sleeping\n",  get_time() - philo->data->start_time, philo->nb);
	pthread_mutex_unlock(philo->data->write);
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
	int	i;
	t_philo *philos;
	
	i = 0;
	philos = (t_philo*)param;
	if (philos->nb % 2 == 0)
		ft_sleep(philos->data->t_to_eat / 2);
	while (is_dead(philos) == 0)
	{
		// printf("philo %i last eaten%i\n", philos->nb, get_time() - philos->last_eaten - philos->data->start_time);
		//mostly done
		if (get_forks(philos) == true)
			return (NULL);
		//mostly done
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
	if (death_check(philo) == true)
		return (1);
	pthread_mutex_lock(philo->data->full_flag);
	if (philo->times_eaten >= philo->data->times_to_eat && philo->data->option)
	{
		pthread_mutex_unlock(philo->data->full_flag);
		return (true);
	}
	pthread_mutex_unlock(philo->data->full_flag);
	return (false);
}
int think(t_philo *philo)
{
	if (death_check(philo) == true)
		return (1);
	pthread_mutex_lock(philo->data->write);
	printf("%i %i is thinking\n",  get_time() - philo->data->start_time, philo->nb);
	pthread_mutex_unlock(philo->data->write);
	return (0);
}