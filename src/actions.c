/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:49:05 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/02 16:52:38 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
void ft_sleep(int ms);

int eat(t_philo *philo)
{
	int i;
	int diff;
	int c;
	
	i = 0;
	c = 0;
	
	if (philo->data->option == true)
		while (i < philo->data->times_to_eat)
		{
			diff = get_time() - philo->data->start_time - c;
			if (diff >= philo->data->t_to_eat)
			{
			printf("%i %i is eating\n", (get_time() - philo->data->start_time), philo->nb);
			i++;
			c += philo->data->t_to_eat;
			}
		}
	else
		while (1)
		{
			diff = get_time() - philo->data->start_time - c;
			if (diff == philo->data->t_to_eat)
			{
			printf("%i %i is eating\n", (get_time() - philo->data->start_time), philo->nb);
			i++;
			c += philo->data->t_to_eat;
			}
		}
	printf("time to eat%i\n", philo->data->t_to_eat);
	return (0);
}

void ft_sleep(int ms)
{
	int cur_time;

	cur_time = get_time();
	printf("%li\n", (get_time() - (long)cur_time));
	// while ((get_time() - cur_time) < ms)
	// {
	// 	printf("test\n");
	// 	usleep(10);
	// }
}