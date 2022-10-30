/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:16 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/30 17:19:36 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_dead(t_table *philo, t_data *data)
{
	long	time;

	pthread_mutex_lock(data->output);
	time = time_update(philo->philosopher->info->starting_time);
	if ((time - philo->philosopher->last_meal) > \
	philo->philosopher->info->time_to_die)
	{
		data->death_time = time_update(philo->philosopher->info->starting_time);
		data->is_dead = philo->philosopher->philo_id;
		pthread_mutex_unlock(data->output);
		return (1);
	}
	pthread_mutex_unlock(data->output);
	return (0);
}

void	routine(t_table *philo, long time, t_data *data)
{
	if (eat(philo, data))
		return ;
	sleeping_time(philo, time, data);
}

void	sleeping_time(t_table *philo, long time, t_data *data)
{
	print_message(time_update(time), philo, "is sleeping  😴", data);
	usleep(philo->philosopher->info->time_to_sleep * 1000);
	thinking_time(philo, time, data);
}

void	thinking_time(t_table *philo, long time, t_data *data)
{
	print_message(time_update(time), philo, "is thinking  🤔", data);
	routine(philo, time, data);
}
