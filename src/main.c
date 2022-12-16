/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:15:55 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/16 19:30:37 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			*philos;

	data_null(&data);
	parce_input(ac, av, &data);
	if (wrong_input(&data) == true)
		return (1);
	init_data(&data);
	philos = malloc(sizeof(t_philo) * data.philo_nb);
	philos = create_philos(&data, philos);
	if (philos == NULL)
	{
		free_locks(philos->data);
		free_all_forks(philos);
		free(philos);
		return (printf_error("philo allocation failed"));
	}
	create_threads(philos);
	free_locks(philos->data);
	free_all_forks(philos);
	free(philos);
	return (EXIT_SUCCESS);
}
