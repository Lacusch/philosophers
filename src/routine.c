/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:49:05 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/16 19:35:21 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *param)
{
	t_philo	*philos;

	philos = (t_philo *)param;
	if (philos->nb % 2 == 0)
		ft_sleep(philos->data->t_to_eat / 2);
	while (death_check(philos) == 0 || full(philos) != true)
	{
		if (eat(philos) == true)
			return (NULL);
		if (to_sleep(philos) == true)
			return (NULL);
		if (death_check(philos) == true)
			return (NULL);
		print_action(philos, "is thinking");
	}
	return (NULL);
}
