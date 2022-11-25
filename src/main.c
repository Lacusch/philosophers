/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:15:55 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/25 15:47:15 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_printf(t_philo *philo);

int	parce_input(int ac, char **av, t_philo *philo)
{
	t_philo	test;

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

int	main(int ac, char **av)
{
	t_philo	philo;

	if (parce_input(ac, av, &philo))
		return (EXIT_FAILURE);
	philo_printf(&philo);
	return (EXIT_SUCCESS);
}

void	philo_printf(t_philo *philo)
{
	printf("%d\n", philo->t_to_die);
	printf("%d\n", philo->t_to_eat);
	printf("%d\n", philo->t_to_sleep);
	printf("%d\n", philo->t_to_eat);
	if (philo->option)
		printf("%d\n", philo->times_to_eat);
}
