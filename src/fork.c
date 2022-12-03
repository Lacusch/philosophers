/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:50:00 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/03 16:17:52 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_right_fork(t_philo *philos)
{
	pthread_mutex_t *mutex;
	mutex = malloc(sizeof(pthread_mutex_t));
	philos->right_fork = malloc(sizeof(t_fork));
	philos->left_fork = NULL;
	philos->right_fork->is_in_use = 0;
	pthread_mutex_init(mutex, NULL);
	philos->right_fork->mutex = mutex;
}

int get_forks(t_philo *philo)
{
	// Even so left fork
	if (philo->nb % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork->mutex) == 0)
			{
				philo->left_fork->is_in_use = true;
				printf("%d %d has taken a fork\n", get_time() - philo->data->start_time, philo->nb);
				pthread_mutex_lock(philo->right_fork->mutex);
				printf("%d %d has taken a fork\n", get_time() - philo->data->start_time, philo->nb);
				philo->right_fork->is_in_use = true;
				philo->state = TOOK_FORKS;
			}
		else
			printf("%d %d fork taken\n", get_time() - philo->data->start_time, philo->nb);
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork->mutex) == 0)
		{
			philo->right_fork->is_in_use = true;
			printf("%d %d has taken a fork\n", get_time() - philo->data->start_time, philo->nb);
			pthread_mutex_lock(philo->left_fork->mutex);
			printf("%d %d has taken a fork\n", get_time() - philo->data->start_time, philo->nb);
			philo->left_fork->is_in_use = true;
			philo->state = TOOK_FORKS;
			give_fork(philo);
		}
		else
			printf("%d %d fork taken\n", get_time() - philo->data->start_time, philo->nb);
	}
	return (EXIT_SUCCESS);
}

int give_fork(t_philo *philo)
{
	if (philo->left_fork->is_in_use == true && philo->right_fork->is_in_use == true)
	{
		pthread_mutex_unlock(philo->left_fork->mutex);
		philo->left_fork->is_in_use = false;
		pthread_mutex_unlock(philo->right_fork->mutex);
		philo->right_fork->is_in_use = false;
	}
	return (EXIT_SUCCESS);
}