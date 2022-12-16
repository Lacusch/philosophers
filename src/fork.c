/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:50:00 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/16 19:28:09 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_right_fork(t_philo *philos)
{
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t));
	philos->right_fork = malloc(sizeof(t_fork));
	philos->left_fork = NULL;
	philos->right_fork->is_in_use = 0;
	pthread_mutex_init(mutex, NULL);
	philos->right_fork->mutex = mutex;
}

void	free_right_fork(t_philo *philo)
{
	pthread_mutex_destroy(philo->right_fork->mutex);
	free(philo->right_fork->mutex);
	philo->right_fork->mutex = NULL;
	free(philo->right_fork);
}
