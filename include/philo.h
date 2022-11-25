/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:14 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/25 15:44:48 by slaszlo-         ###   ########.fr       */
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
//Treads
# include <pthread.h>

/**
 *  
 * @abstract Properties of the philosopthers
 */

/**
 * @typedef t_philo
 * @brief Properties of the philosophers
 */
typedef struct philo
{
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	bool	option;
	int		times_to_eat;
}	t_philo;

#endif