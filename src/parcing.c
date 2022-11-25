/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:55:06 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/25 18:21:12 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	parce_input(int ac, char **av, t_data_philo *philo)
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
	philo->philo_nb = atoi(av[1]);
	philo->t_to_die = atoi(av[2]);
	philo->t_to_eat = atoi(av[3]);
	philo->t_to_sleep = atoi(av[4]);
	if (ac == 6)
	{
		philo->option = true;
		philo->times_to_eat = atoi(av[5]);
	}
	return (EXIT_SUCCESS);
}
