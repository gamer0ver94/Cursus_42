/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/28 12:39:27 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*start(void *args)
{
	t_data			*data;
	t_table			*table;

	data = (t_data *)(args);
	sem_wait(data->s_status);
	table = data->table;
	data->table = data->table->right;
	sem_post(data->s_status);
	eating_time(table, table->philosopher->info->starting_time, data);
	return (NULL);
}

int	*controller(void *args)
{
	t_data	*data;
	t_table	*tmp;

	data = (t_data *)(args);
	data->is_dead = FALSE;

	tmp = data->table;
	while (1)
	{
		sem_wait(data->output);
		if (data->info->eat_time_rules == TRUE && \
		tmp->philosopher->n_diner == 0)
		{
			printf("%ld %d ate all\n", tmp->philosopher->finish_eat_time, \
			tmp->philosopher->philo_id);
			return (0);
		}
		return (0);
	}
	printf("%ld %d died\n", tmp->philosopher->death_time, \
	tmp->philosopher->philo_id);
	return (0);
}

void	simulation(t_data *data)
{
	semaphore_init(data);
	processes_init(data);
	while (1);
}
