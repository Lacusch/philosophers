/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:15:55 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/14 11:06:47 by slaszlo-         ###   ########.fr       */
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
	create_threads(philos);
	free(philos);
	return (EXIT_SUCCESS);
}

