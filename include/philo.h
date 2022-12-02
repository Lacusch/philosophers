/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:14 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/02 17:56:07 by slaszlo-         ###   ########.fr       */
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
//for time
#include <sys/time.h>
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
	int	start_time;
}	t_data_philo;

typedef struct fork
{
	pthread_mutex_t	*mutex;
	bool			is_in_use;
}	t_fork;

typedef enum state
{
	TOOK_FORKS = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	DIED = 4,
	IDLE = 5
} t_state;
typedef struct philo
{
	int		eaten;
	bool	is_dead;
	int		nb;
	t_fork	*left_fork;
	t_fork	*right_fork;
	t_data_philo	*data;
	pthread_t thread;
}	t_philo;
//actions.c

int eat(t_philo *philo);
void ft_sleep(int ms);
void	*routine(void *param);

//fork.c

void	create_right_fork(t_philo *philos);

//main.c

int eat(t_philo *philo);

//parcing.c

int		parce_input(int ac, char **av, t_data_philo *philo);

//philos.c
t_philo *create_philos(t_data_philo *data);

//thread.c

int create_threads(t_philo *philos);

//time.c

int get_time(void);

//utils.c

void	philo_printf(t_data_philo *philo);

#endif