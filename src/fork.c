/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:50:00 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/11 18:20:08 by slaszlo-         ###   ########.fr       */
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

void print_fork(t_philo *philo)
{
	//If philo dead return ;
	pthread_mutex_lock(philo->data->write);
	printf("%d %d has taken a fork\n", get_time() -philo->data->start_time, philo->nb);
	pthread_mutex_unlock(philo->data->write);
}
int get_forks(t_philo *philo)
{
	//have a case where there is only one philo
	if (death_check(philo) == true)
		return (true);
	pthread_mutex_lock(philo->left_fork->mutex);
	print_fork(philo);
	if (philo->data->philo_nb == 1)
	{
		ft_sleep(philo->data->t_to_die);
		is_dead(philo);
		return (1);
	}
	if (death_check(philo) == true)
	{
		pthread_mutex_unlock(philo->left_fork->mutex);
		return (true);
	}
	pthread_mutex_lock(philo->right_fork->mutex);
	print_fork(philo);
	return (EXIT_SUCCESS);
}

int give_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork->mutex);
	philo->left_fork->is_in_use = false;
	pthread_mutex_unlock(philo->right_fork->mutex);
	philo->right_fork->is_in_use = false;
	return (EXIT_SUCCESS);
}