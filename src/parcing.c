/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:55:06 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/16 17:59:30 by slaszlo-         ###   ########.fr       */
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
	else if (data->t_to_die <= 0)
		return (printf_error("invalid time to die"));
	else if (data->t_to_eat <= 0)
		return (printf_error("invalid time to eat"));
	else if (data->t_to_sleep <= 0)
		return (printf_error("invalid time to sleep"));
	else if (data->option && data->times_to_eat <= 0)
		return (printf_error("invalid times to eat"));
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
	data->philo_nb = ft_atoi(av[1]);
	data->t_to_die = ft_atoi(av[2]);
	data->t_to_eat = ft_atoi(av[3]);
	data->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->option = true;
		data->times_to_eat = ft_atoi(av[5]);
		if (data->times_to_eat == 0)
			data->full = data->philo_nb;
	}
	else
		data->times_to_eat = -1;
	return (EXIT_SUCCESS);
}



int	ft_atoi(char *str)
{
	int	c;
	int	operator;
	int	out;

	c = 0;
	operator = 1;
	out = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' '
		|| str[c] == '\n' || str[c] == '\v' || str[c] == '\f')
	{
		c++;
	}
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			operator = -operator;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		out = (str[c] - '0') + (out * 10);
		c++;
	}
	return (out * operator);
}