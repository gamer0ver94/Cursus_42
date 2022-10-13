/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:16 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/13 10:08:33 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void eat(pthread_mutex_t *fork1, pthread_mutex_t *fork2, t_table *philo)
{
	pthread_mutex_lock(fork1);
	pthread_mutex_lock(fork2);
	printf("%ld     philo->%d is eating\n", philo->timestamp->time, philo->philosopher->philo_id);
//realease fork
	sleep(5);
	pthread_mutex_unlock(fork1);
	pthread_mutex_unlock(fork2);
	printf("%ld     philo->%d finish eat\n",  philo->timestamp->time, philo->philosopher->philo_id);
	(void)fork1;
	(void)fork2;
}

void sleeping()
{
	usleep(5000 * 5);
}

void think()
{
	sleep(6);
}