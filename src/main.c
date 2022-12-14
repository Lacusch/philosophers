/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:15:55 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/14 14:03:06 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo			*philos;

	if (parce_input(ac, av, &data))
		return (EXIT_FAILURE);
	init_data(&data);
	philos = malloc(sizeof(t_philo) * data.philo_nb);
	if (philos == NULL)
		return(free(philos), printf_error("philo allocation failed"));
	philos = create_philos(&data);
	//Also free philo data
	if (philos == NULL)
		return(free(philos), printf_error("philo allocation failed"));
	printf("number of times to eat%i, number of philos full%i\n", philos->data->times_to_eat, philos->data->full);
	printf("The number of philos is%i\n", philos->data->philo_nb);
	create_threads(philos);
	free(philos);
	return (EXIT_SUCCESS);
}

