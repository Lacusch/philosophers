/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heibronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:12:42 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/11/26 17:35:24 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long get_time(void)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	// printf("time is %li\n", (tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return((long)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}