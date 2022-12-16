/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:38:27 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/16 13:26:22 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_action(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->write);
	if ((death_check(philo) == false || ft_strcmp(str, "died") == 0) && full(philo) == false)
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
	if (philo->data->philo_nb == 1)
	{
		ft_sleep(philo->data->t_to_die);
		return (1);
	}
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
	bool b_full;

	if (death_check(philo) == true)
		return (true);
	if (take_fork(philo) == 1)
		return (1);
	set_status(philo, true);
	print_action(philo, "is eating");
	set_last_eaten(philo, get_time() - philo->data->start_time);
	philo->times_eaten++;
	b_full = philo->times_eaten == philo->data->times_to_eat;
	ft_sleep(philo->data->t_to_eat);
	return_fork(philo);
	if (b_full && philo->data->times_to_eat != -1)
		increase_full(philo);
	return (0);
}

int to_sleep(t_philo *philo)
{
	if (death_check(philo) == true)
		return (true);
	print_action(philo, "is sleeping");
	set_status(philo, false);
	ft_sleep(philo->data->t_to_sleep);
	return (0);
}