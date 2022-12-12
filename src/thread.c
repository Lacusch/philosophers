/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:12:17 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/12 10:49:24 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int create_threads(t_philo *philos)
{
	int i;
	i = 0;;
	while (i < philos->data->philo_nb)
	{
		pthread_create(&philos[i].thread, NULL, &routine, (void *)&philos[i]);
		i++;
	}
	monitoring(philos);
	i = 0;
	while (i < philos->data->philo_nb)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (EXIT_FAILURE);
}