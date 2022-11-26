/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:15:55 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/26 13:42:16 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_philos(t_philo *philos, t_data_philo *data);
void	create_fork(t_philo *philos);

void	*routine(void *param)
{
	int	i;
	int	*index;

	index = ((int *)(param));
	i = 0;
	printf("philo %i is created\n", *index);
	while (i < 3)
	{
		printf("eating\n");
		i++;
		sleep(1);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data_philo	data;
	t_philo			*philos;

	philos = NULL;

	if (parce_input(ac, av, &data))
		return (EXIT_FAILURE);
	philos = malloc(data.philo_nb * sizeof(t_philo));
	philo_printf(&data);
	create_philos(philos, &data);
	return (EXIT_SUCCESS);
}

void	create_fork(t_philo *philos)
{
	pthread_mutex_t *mutex;
	mutex = malloc(sizeof(pthread_mutex_t));
	philos->fork = malloc(sizeof(t_fork));
	philos->fork->is_in_use = 0;
	pthread_mutex_init(mutex, NULL);
	philos->fork->mutex = mutex;
}

void	create_philos(t_philo *philos, t_data_philo *data)
{
	int			i;
	pthread_t	*thread;

	i = 0;
	thread = malloc(sizeof(thread) * data->philo_nb);
	philos = malloc(sizeof(t_philo) * data->philo_nb);
	while (i < data->philo_nb)
	{
		int *tmp = malloc(sizeof(int));
		*tmp = i;
		create_fork(&philos[i]);
		philos[i].nb = *tmp;
		philos[i].eaten = 0;
		philos[i].is_dead = 0;
		pthread_create(thread + i, NULL, &routine, tmp);
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		printf("philo number is%i\n", philos[i].nb);
		printf("philo %i lock status is:%i\n", philos[i].nb, philos[i].fork->is_in_use);
		i++;
	}
}
