/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/29 22:19:11 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void eat(pthread_mutex_t *fork1, pthread_mutex_t *fork2)
{
	(void)fork1;
	(void)fork2;
	sleep(5);
}

void sleeping()
{
	usleep(5000 * 5);
}

void think()
{
	sleep(6);
}

void *start(t_table *table)
{
	struct timeval	current_time;
	long			initial_time;
	long			time;

	gettimeofday(&current_time, NULL);
	initial_time = current_time.tv_sec * 1000;
	pthread_mutex_lock(&table->philosopher->fork);
	pthread_mutex_lock(&table->right->philosopher->fork);
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) - initial_time;
	printf("%ld ->philo %d IS EATING\n",time, table->philosopher->philo_id);
	eat(&table->philosopher->fork, &table->right->philosopher->fork);
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) - initial_time;
	printf("%ld ->philo %d finisheating\n", time,  table->philosopher->philo_id);
	printf("__________________________\n");
	pthread_mutex_unlock(&table->philosopher->fork);
	pthread_mutex_unlock(&table->right->philosopher->fork);
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) - initial_time;
	printf("%ld ->philo %d IS SLEEPING\n",time, table->philosopher->philo_id);
	sleeping();
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) - initial_time;
	printf("%ld ->philo %d IS THINKING\n",time , table->philosopher->philo_id);
	think();
	start(table);
	return (0);
}

void	simulation(t_table *table, t_info *info)
{
	mutex_init(table, info);
	threads_init(table, info);
	wait_threads(table, info);
}
