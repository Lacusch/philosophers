/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:15:55 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/02 17:56:20 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_data_philo	data;
	t_philo			*philos;

	philos = NULL;

	if (parce_input(ac, av, &data))
		return (EXIT_FAILURE);
	philos = create_philos(&data);
	create_threads(philos);
	return (EXIT_SUCCESS);
}

