/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:54:10 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/16 18:16:53 by slaszlo-         ###   ########.fr       */
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

int ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void data_null(t_data *data)
{
	data->philo_nb = 0;
	data->t_to_die = 0;
	data->t_to_eat = 0;
	data->t_to_sleep = 0;
	data->option = 0;
	data->times_to_eat = 0;
	data->start_time = 0;
	data->philo_died = 0;
	data->full = 0;
	data->write = NULL;
	data->time_check = NULL;
	data->death_check = NULL;
	data->full_flag = NULL;
	data->is_eating = NULL;
}

void free_all_forks(t_philo *philo)
{
	int			i;
	i = 0;

	while (i < philo->data->philo_nb)
	{
		free_right_fork(&philo[i]);
		i++;
	}
}