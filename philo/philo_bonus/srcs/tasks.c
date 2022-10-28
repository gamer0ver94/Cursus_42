/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:16 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/27 14:49:27 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_dead(t_table *philo, t_data *data)
{
	long	time;

	sem_wait(data->output);
	time = time_update(philo->philosopher->info->starting_time);
	if ((time - philo->philosopher->last_meal) > \
	philo->philosopher->info->time_to_die && data->is_dead == 0)
	{
		philo->philosopher->death_time = time;
		data->is_dead = philo->philosopher->philo_id;
		sem_post(data->output);
		return (1);
	}
	else if (data->is_dead)
	{
		sem_post(data->output);
		return (1);
	}
	sem_post(data->output);
	return (0);
}

void	eating_time(t_table *philo, long time, t_data *data)
{
	sem_wait(data->fork);
	sem_wait(data->fork);
	if (!is_dead(philo, data))
	{
		print_message(time_update(time), philo, "has taken a fork  🍴", data);
		print_message(time_update(time), philo, "has taken a fork  🍴", data);
		print_message(time_update(time), philo, "is eating  🍽", data);
	}
	else
		exit(0);
	philo->philosopher->last_meal = time_update(time);
	usleep(philo->philosopher->info->time_to_eat * 1000);
	sem_wait(data->output);
	philo->philosopher->n_diner--;
	if (philo->philosopher->info->eat_time_rules == TRUE \
	&& philo->philosopher->n_diner == 0)
	{
		philo->philosopher->finish_eat_time = time_update(philo->philosopher->info->starting_time);
		sem_post(data->output);
		exit(0);
	}
	sem_post(data->output);
	sem_post(data->fork);
	sem_post(data->fork);
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
