/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:16 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/17 13:57:54 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void eating_time(pthread_mutex_t *fork1, pthread_mutex_t *fork2, t_table *philo, long time)
{
	pthread_mutex_lock(fork1);
	pthread_mutex_lock(fork2);
    philo->philosopher->eating = 1;
	printf("%ld     philo->%d is eating\n", time_update(time), philo->philosopher->philo_id);
	usleep(philo->philosopher->info->time_to_eat * 1000);
	pthread_mutex_unlock(fork1);
	pthread_mutex_unlock(fork2);
    philo->philosopher->eating = 0;
    philo->philosopher->last_meal = time_update(time);
	printf("%ld     philo->%d finish eat\n", time_update(time), philo->philosopher->philo_id);
    sleeping_time(philo, time);
}

void    sleeping_time(t_table *philo, long time)
{
    printf("%ld     philo->%d is sleeping\n", time_update(time), philo->philosopher->philo_id);
    usleep(philo->philosopher->info->time_to_sleep * 1000);
    printf("%ld     philo->%d is wake\n", time_update(time), philo->philosopher->philo_id);
}

void    thinking_time(t_table *philo, long time)
{
     printf("%ld     philo->%d is thinking\n", time_update(time), philo->philosopher->philo_id);
}