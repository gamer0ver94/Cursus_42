/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:16 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/24 12:40:26 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eating_time(t_table *philo, long time, t_data *data)
{
	if (pthread_mutex_lock(&philo->philosopher->fork) == 0 && pthread_mutex_lock(&philo->right->philosopher->fork) == 0)
	{
		print_message(time_update(time), philo, "has taken a fork  🍴");
		print_message(time_update(time), philo, "has taken a fork  🍴");
	}
	else
		printf("error\n");
	if ((time_update(philo->philosopher->info->starting_time) - philo->philosopher->last_meal) < philo->philosopher->info->time_to_die)
	{
		philo->philosopher->is_eating = TRUE;
		print_message(time_update(time), philo, "is eating  🍽");
		usleep(philo->philosopher->info->time_to_eat * 1000);
		philo->philosopher->n_diner--;
		if (philo->philosopher->info->eat_time_rules == TRUE && philo->philosopher->n_diner == 0)
		{
			pthread_mutex_lock(&data->sim_status);
		}
		philo->philosopher->is_eating = FALSE;
		pthread_mutex_unlock(&philo->philosopher->fork);
		pthread_mutex_unlock(&philo->right->philosopher->fork);
		philo->philosopher->last_meal = time_update(time);
		sleeping_time(philo, time, data);
	}
}

void	sleeping_time(t_table *philo, long time, t_data *data)
{
	print_message(time_update(time), philo, "is sleeping  😴");
	usleep(philo->philosopher->info->time_to_sleep * 1000);
	thinking_time(philo, time, data);
}

void	thinking_time(t_table *philo, long time, t_data *data)
{
	print_message(time_update(time), philo, "is thinking  🤔");
	eating_time(philo, time, data);
}
