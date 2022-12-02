/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:54:22 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/02 17:54:30 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo *create_philos(t_data_philo *data)
{
	int			i;
	i = 0;

	t_philo *philos;
	data->start_time = get_time();
	philos = malloc(sizeof(t_philo) * data->philo_nb);
	while (i < data->philo_nb)
	{
		create_right_fork(&philos[i]);
		if (i != 0)
		{
			philos[i].left_fork = philos[i - 1].right_fork;
		}
		philos[i].nb = i + 1;
		philos[i].eaten = 0;
		philos[i].is_dead = false;
		philos[i].data = data;
		if (philos[i].nb == data->philo_nb)
		{
			philos[0].left_fork = philos[i].right_fork;
		}
		
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		printf("philo number is:%i\n", philos[i].nb);
		printf("philo %i right fork status:%i\n", philos[i].nb, philos[i].right_fork->is_in_use);
		printf("philo %i left fork status:%i\n", philos[i].nb, philos[i].left_fork->is_in_use);
		printf("\n");
		i++;
	}
	return (philos);
}