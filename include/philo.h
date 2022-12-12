/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:14 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/12/12 15:43:46 by slaszlo-         ###   ########.fr       */
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
typedef struct s_data
{
	int				philo_nb;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	bool			option;
	int				times_to_eat;
	int				start_time;
	bool			philo_died;
	int				full;
	pthread_mutex_t	*write;
	pthread_mutex_t	*time_check;
	pthread_mutex_t	*death_check;
	pthread_mutex_t	*full_flag;
	pthread_mutex_t	*is_eating;
}	t_data;

typedef struct s_fork
{
	pthread_mutex_t	*mutex;
	bool			is_in_use;
}	t_fork;

typedef struct s_philo
{
	int		times_eaten;
	bool	is_dead;
	int		nb;
	int		last_eaten;
	bool	eating;
	t_fork	*left_fork;
	t_fork	*right_fork;
	t_data	*data;
	pthread_t thread;
}	t_philo;
//actions.c

void print_action(t_philo *philo, char *str);
int return_fork(t_philo *philo);
int take_fork(t_philo *philo);
int eat(t_philo *philo);
int to_sleep(t_philo *philo);

//check.c

bool death_check(t_philo *philo);
bool full(t_philo *philo);
int	get_last_eaten(t_philo *philo);
bool check_eating(t_philo *philo);

//fork.c

void	create_right_fork(t_philo *philos);

//main.c

int eat(t_philo *philo);

//monitoring.c

void monitoring(t_philo *philos);
bool is_dead(t_philo *philos);
//parcing.c

int	parce_input(int ac, char **av, t_data *data);
bool printf_error(char* str);
bool wrong_input(t_data *data);

//philos.c

t_philo *create_philos(t_data *data);
int init_data(t_data *data);
int init_locks(t_data *data);

//routine.c

void	*routine(void *param);
int think(t_philo *philo);
bool full_check (t_philo *philo);

//set.c

void set_death(t_philo *philo);
void increase_full(t_philo	*philo);
void set_status(t_philo *philo, bool status);
void set_last_eaten(t_philo *philo, int time);

//thread.c

int create_threads(t_philo *philos);

//time.c

int get_time(void);

//utils.c

void	philo_printf(t_data *philo);
void ft_sleep(int ms);

#endif