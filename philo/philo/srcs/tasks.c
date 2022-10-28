/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:16 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/27 12:45:43 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_dead(t_table *philo, t_data *data)
{
	long	time;

	pthread_mutex_lock(data->output);
	time = time_update(philo->philosopher->info->starting_time);
	if ((time - philo->philosopher->last_meal) > \
	philo->philosopher->info->time_to_die && data->is_dead == 0)
	{
		philo->philosopher->death_time = time;
		data->is_dead = philo->philosopher->philo_id;
		pthread_mutex_unlock(data->output);
		return (1);
	}
	else if (data->is_dead)
	{
		pthread_mutex_unlock(data->output);
		return (1);
	}
	pthread_mutex_unlock(data->output);
	return (0);
}

void	eating_time(t_table *philo, long time, t_data *data)
{
	pthread_mutex_lock(philo->philosopher->fork);
	pthread_mutex_lock(philo->right->philosopher->fork);
	if (!is_dead(philo, data))
	{
		print_message(time_update(time), philo, "has taken a fork  🍴", data);
		print_message(time_update(time), philo, "has taken a fork  🍴", data);
		print_message(time_update(time), philo, "is eating  🍽", data);
	}
	else
		return ;
	philo->philosopher->last_meal = time_update(time);
	usleep(philo->philosopher->info->time_to_eat * 1000);
	pthread_mutex_lock(data->output);
	philo->philosopher->n_diner--;
	if (philo->philosopher->info->eat_time_rules == TRUE \
	&& philo->philosopher->n_diner == 0)
	{
		philo->philosopher->finish_eat_time = time_update(philo->philosopher->info->starting_time);
		pthread_mutex_unlock(data->output);
		return ;
	}
	pthread_mutex_unlock(data->output);
	pthread_mutex_unlock(philo->philosopher->fork);
	pthread_mutex_unlock(philo->right->philosopher->fork);
	sleeping_time(philo, time, data);
}

void	sleeping_time(t_table *philo, long time, t_data *data)
{
	if (!is_dead(philo, data))
	{
		print_message(time_update(time), philo, "is sleeping  😴", data);
		usleep(philo->philosopher->info->time_to_sleep * 1000);
		thinking_time(philo, time, data);
	}
}

void	thinking_time(t_table *philo, long time, t_data *data)
{
	if (!is_dead(philo, data))
	{
		print_message(time_update(time), philo, "is thinking  🤔", data);
		eating_time(philo, time, data);
	}
}
