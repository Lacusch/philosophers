/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:06:03 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/12 11:07:46 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_action(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->write);
	printf("%i %i %s\n",  get_time() - philo->data->start_time, philo->nb, str);
	pthread_mutex_unlock(philo->data->write);
}