/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:55:06 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/05 14:36:39 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	parce_input(int ac, char **av, t_data *data)
{
	if (ac < 5)
	{
		printf ("not enough arguments\n");
		return (EXIT_FAILURE);
	}
	else if (ac > 6)
	{
		printf ("too many arguments\n");
		return (EXIT_FAILURE);
	}
	data->philo_nb = atoi(av[1]);
	data->t_to_die = atoi(av[2]);
	data->t_to_eat = atoi(av[3]);
	data->t_to_sleep = atoi(av[4]);
	if (ac == 6)
	{
		data->option = true;
		data->times_to_eat = atoi(av[5]);
	}
	return (EXIT_SUCCESS);
}
