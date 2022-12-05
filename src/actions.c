/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:49:05 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/05 12:09:25 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int think(t_philo *philo);

int eat(t_philo *philo)
{
	if (philo->state == TOOK_FORKS)
	{
		philo->last_eaten = get_time() - philo->data->start_time;
		printf("%i %i is eating\n",  get_time() - philo->data->start_time, philo->nb);
		ft_sleep(philo->data->t_to_eat);
		give_fork(philo);
		philo->state = IDLE;
		philo->times_eaten++;
	}
	return (0);
}

int to_sleep(t_philo *philo)
{
	printf("%i %i is sleeping\n",  get_time() - philo->data->start_time, philo->nb);
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
	while (!philos->is_dead)
	{
		i++;
		printf("philo %i last eaten%i\n", philos->nb, philos->last_eaten);
		get_forks(philos);
		eat(philos);
		to_sleep(philos);
		think(philos);
		if (i >= philos->data->times_to_eat && philos->data->option)
				break;
	}
	return (NULL);
}

int think(t_philo *philo)
{
	printf("%i %i is thinking\n",  get_time() - philo->data->start_time, philo->nb);
	return (0);
}