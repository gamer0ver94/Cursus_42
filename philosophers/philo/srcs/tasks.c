/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:16 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/22 14:34:34 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eating_time(pthread_mutex_t *fork1, pthread_mutex_t *fork2, \
t_table *philo, long time)
{
	if (pthread_mutex_lock(fork1) == 0 && pthread_mutex_lock(fork2) == 0)
		print_message(time_update(time), philo, "has taken a fork  🍴");
	else
		printf("error\n");
	if ((time_update(philo->philosopher->info->starting_time) - philo->philosopher->last_meal) < philo->philosopher->info->time_to_die)
	{
		if (pthread_mutex_lock(&philo->philosopher->eating) == 0)
		{
			print_message(time_update(time), philo, "is eating  🍽");
		}
		else
			printf("error\n");
		usleep(philo->philosopher->info->time_to_eat * 1000);
		if (pthread_mutex_unlock(&philo->philosopher->eating) == 0)
		{
			philo->philosopher->n_diner--;
			if (philo->philosopher->info->eat_time_rules == TRUE && philo->philosopher->n_diner == 0)
			{
				pthread_mutex_lock(&philo->philosopher->all_ate);
			}
			philo->philosopher->last_meal = time_update(time);
			pthread_mutex_unlock(fork1);
			pthread_mutex_unlock(fork2);
			sleeping_time(fork1, fork2, philo, time);
		}
		else
			printf("error\n");
	}
	else
		return ;
}

void	sleeping_time(pthread_mutex_t *fork1, pthread_mutex_t *fork2, \
t_table *philo, long time)
{
	print_message(time_update(time), philo, "is sleeping  😴");
	usleep(philo->philosopher->info->time_to_sleep * 1000);
	thinking_time(fork1, fork2, philo, time);
}

void	thinking_time(pthread_mutex_t *fork1, pthread_mutex_t *fork2, \
t_table *philo, long time)
{
	print_message(time_update(time), philo, "is thinking  🤔");
	eating_time(fork1, fork2, philo, time);
}
