/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:25:18 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/12 12:48:46 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool death_check(t_philo *philo)
{
	bool ret;

	pthread_mutex_lock(philo->data->death_check);
	ret = philo->data-> philo_died;
	pthread_mutex_unlock(philo->data->death_check);
	return (ret);
}



