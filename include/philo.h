/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:14 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/26 13:38:56 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @header     philo.h
 * @abstract    All functions for the philosophers.
 * @version     0.1
 * @author      slaszlo- <slaszlo-@student.42heibronn.de>
 * @link        Intra profile <https://profile.intra.42.fr/users/slaszlo->
*/
#ifndef PHILO_H
# define PHILO_H
//For printf
# include <stdio.h>
# include <stdbool.h>
//For NULL
# include <stdlib.h>
//treads
# include <pthread.h>
//for sleep
# include <unistd.h>
/**
 *  
 * @abstract Properties of the philosopthers
 */

/**
 * @typedef t_data_philo
 * @brief Properties of the philosophers
 */
typedef struct data
{
	int		philo_nb;
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	bool	option;
	int		times_to_eat;
}	t_data_philo;

typedef struct fork
{
	pthread_mutex_t	*mutex;
	bool			is_in_use;
}	t_fork;

typedef struct philo
{
	int		eaten;
	bool	is_dead;
	int		nb;
	t_fork	*fork;
}	t_philo;
//parcing.c

int		parce_input(int ac, char **av, t_data_philo *philo);

//utils.c

void	philo_printf(t_data_philo *philo);

#endif