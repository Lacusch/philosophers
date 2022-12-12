/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:55:06 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/12 15:37:12 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool printf_error(char* str)
{
	if (str == NULL)
		printf("Error\n");
	else
		printf("Error\n%s\n", str);
	return (true);
}

bool wrong_input(t_data *data)
{
	if (data->philo_nb == 0)
		return (printf_error("no philo"));
	else if (data->philo_nb < 0)
		return (printf_error("negative philo nb"));
	else if (data->t_to_die < 0)
		return (printf_error("negative time to die"));
	else if (data->t_to_eat < 0)
		return (printf_error("negative time to eat"));
	else if (data->t_to_sleep < 0)
		return (printf_error("negative time to sleep"));
	else if (data->option && data->times_to_eat < 0)
		return (printf_error("the amout of times to eat is negative"));
	else
		return (false);
}
int	parce_input(int ac, char **av, t_data *data)
{
	if (ac < 5)
	{
		printf_error("not enough arguments");
		return (EXIT_FAILURE);
	}
	else if (ac > 6)
	{
		printf_error ("too many arguments");
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
	else
		data->times_to_eat = -1;
	if (wrong_input(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
