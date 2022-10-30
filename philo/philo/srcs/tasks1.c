/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:15:25 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/30 17:27:10 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	take_forks(t_table *table ,t_data *data)
{
	t_philosopher	*philo;
	long			time;

	philo = table->philosopher;
	time = philo->info->starting_time;
	if (pthread_mutex_lock(philo->fork) == 0 && \
	pthread_mutex_lock(table->right->philosopher->fork) == 0)
	{
		print_message(time_update(time), table, "has taken a fork  🍴", data);
		print_message(time_update(time), table, "has taken a fork  🍴", data);
	}
	return (0);
}

int	realease_forks(t_table *table ,t_data *data)
{
	t_philosopher	*philo;

	(void)data;
	philo = table->philosopher;
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(table->right->philosopher->fork);
	return (0);
}

int	eat(t_table *table, t_data *data)
{
	t_philosopher	*philo;

	philo = table->philosopher;

	take_forks(table, data);
	print_message(time_update(philo->info->starting_time), \
	table, "is eating 🍴", data);
	philo->last_meal = time_update(data->info->starting_time);
	usleep(philo->info->time_to_eat * 1000);
	philo->n_diner--;
	if (philo->info->eat_time_rules == TRUE \
		&& philo->n_diner == 0)
	{
		pthread_mutex_lock(data->s_status);
		philo->finish_eat_time = time_update(philo->info->starting_time);
		data->n_ate_all--;
		philo->n_diner = -1;
		pthread_mutex_unlock(data->s_status);
		realease_forks(table, data);
		return (1);
	}
	realease_forks(table, data);
	return (0);
}
