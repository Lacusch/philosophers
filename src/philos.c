/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:54:22 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/07 13:45:28 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo *create_philos(t_data *data)
{
	int			i;
	i = 0;

	t_philo *philos;
	// data->start_time = get_time();
	philos = malloc(sizeof(t_philo) * data->philo_nb);
	while (i < data->philo_nb)
	{
		create_right_fork(&philos[i]);
		if (i != 0)
		{
			philos[i].left_fork = philos[i - 1].right_fork;
		}
		philos[i].nb = i + 1;
		philos[i].times_eaten = 0;
		philos[i].is_dead = false;
		philos[i].data = data;
		philos[i].state = IDLE;
		philos[i].last_eaten = 0;
		if (philos[i].nb == data->philo_nb)
		{
			philos[0].left_fork = philos[i].right_fork;
		}
		
		i++;
	}
	i = 0;
	// while (i < data->philo_nb)
	// {
	// 	printf("philo number is:%i\n", philos[i].nb);
	// 	printf("philo %i right fork status:%i\n", philos[i].nb, philos[i].right_fork->is_in_use);
	// 	printf("philo %i left fork status:%i\n", philos[i].nb, philos[i].left_fork->is_in_use);
	// 	printf("\n");
	// 	i++;
	// }
	return (philos);
}

int init_locks(t_data *data)
{
	if (data == NULL)
		return(EXIT_FAILURE);
	data->death_check = malloc(sizeof(pthread_mutex_t));
	data->time_check = malloc(sizeof(pthread_mutex_t));
	data->full_flag = malloc(sizeof(pthread_mutex_t));
	data->meal_count = malloc(sizeof(pthread_mutex_t));
	data->write = malloc(sizeof(pthread_mutex_t));
	if (data->death_check == NULL || data->time_check == NULL || data->full_flag == NULL || data->meal_count == NULL || data->write == NULL)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(data->death_check, NULL) != 0 ||
		pthread_mutex_init(data->time_check, NULL) != 0 ||
		pthread_mutex_init(data->full_flag, NULL) != 0 ||
		pthread_mutex_init(data->meal_count, NULL) != 0 ||
		pthread_mutex_init(data->write, NULL) != 0
		 )
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
int init_data(t_data *data)
{
	data->philo_died = false;
		data->start_time = get_time();
	if (init_locks(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (0);
}