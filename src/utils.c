/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:54:10 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/12 13:06:51 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_printf(t_data *philo)
{
	printf("Number of philo:%d\n", philo->philo_nb);
	printf("Time to die is:%d\n", philo->t_to_die);
	printf("Time to eat is:%d\n", philo->t_to_eat);
	printf("Time to sleep is:%d\n", philo->t_to_sleep);
	if (philo->option)
		printf("Times to eat%d\n", philo->times_to_eat);
}

void ft_sleep(int ms)
{
	int cur_time;

	cur_time = get_time();
	while ((get_time() - cur_time) < ms)
	{
		usleep(500);
	}
}
