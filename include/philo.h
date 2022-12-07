/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:14 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/07 13:56:45 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/**
 * @header     philo.h
 * @abstract    All functions for the philosophers.
 * @version     0.5
 * @author      slaszlo- <slaszlo-@student.42heibronn.de>
 * @link        Intra profile <https://profile.intra.42.fr/users/slaszlo->
*/

//For printf
# include <stdio.h>
//For bool
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
 * @typedef t_data
 * @brief Properties of the philosophers
 */
typedef struct data
{
	int				philo_nb;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	bool			option;
	int				times_to_eat;
	int				start_time;
	bool			philo_died;
	pthread_mutex_t	*write;
	pthread_mutex_t	*time_check;
	pthread_mutex_t	*death_check;
	pthread_mutex_t	*full_flag;
	pthread_mutex_t	*meal_count;
}	t_data;

	pthread_mutex_t		*death_flag;
	
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
	int		times_eaten;
	bool	is_dead;
	int		nb;
	int		last_eaten;
	t_state	state;
	t_fork	*left_fork;
	t_fork	*right_fork;
	t_data	*data;
	pthread_t thread;
}	t_philo;
//actions.c

int eat(t_philo *philo);
void ft_sleep(int ms);
void	*routine(void *param);

//eat.c

int eat(t_philo *philo);

//fork.c

void	create_right_fork(t_philo *philos);
int get_forks(t_philo *philo);
int give_fork(t_philo *philo);

//main.c

int eat(t_philo *philo);

//monitoring.c

void monitoring(t_philo *philos);
bool is_dead(t_philo *philos);

//parcing.c

int	parce_input(int ac, char **av, t_data *data);

//philos.c
t_philo *create_philos(t_data *data);
int init_data(t_data *data);
int init_locks(t_data *data);

//thread.c

int create_threads(t_philo *philos);

//time.c

int get_time(void);

//utils.c

void	philo_printf(t_data *philo);

#endif