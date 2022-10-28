/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/27 12:44:02 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*start(void *args)
{
	t_data			*data;
	t_table			*table;

	data = (t_data *)(args);
	pthread_mutex_lock(data->s_status);
	table = data->table;
	data->table = data->table->right;
	pthread_mutex_unlock(data->s_status);
	eating_time(table, table->philosopher->info->starting_time, data);
	return (NULL);
}

t_table	*controller(void *args)
{
	t_data	*data;
	t_table	*tmp;

	data = (t_data *)(args);
	data->is_dead = FALSE;
	threads_init(data);
	tmp = data->table;
	while (!is_dead(tmp, data))
	{
		pthread_mutex_lock(data->output);
		if (data->info->eat_time_rules == TRUE && \
		tmp->philosopher->n_diner == 0)
		{
			printf("%ld %d ate all\n", tmp->philosopher->finish_eat_time, \
			tmp->philosopher->philo_id);
			return ((void *)tmp);
		}
		pthread_mutex_unlock(data->output);
		tmp = tmp->right;
	}
	printf("%ld %d died\n", tmp->philosopher->death_time, \
	tmp->philosopher->philo_id);
	return ((void *)tmp);
}

void	simulation(t_data *data)
{
	pthread_t	simulation;
	t_table		*status;

	data->s_status = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->s_status, NULL);
	data->output = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->output, NULL);
	pthread_create(&simulation, NULL, (void *)controller, (t_data *)(data));
	pthread_join(simulation, (void *)&status);
	pthread_mutex_unlock(data->output);
	pthread_mutex_destroy(data->output);
	pthread_mutex_destroy(data->s_status);
}
