/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/27 14:37:23 by dpaulino         ###   ########.fr       */
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

t_table	*controller(void *args)
{
	t_data	*data;
	t_table	*tmp;

	data = (t_data *)(args);
	data->is_dead = FALSE;
	semaphore_init(data);
	processes_init(data);
	tmp = data->table;
	usleep(1000);
	while (!is_dead(tmp, data))
	{
		sem_wait(data->output);
		if (data->info->eat_time_rules == TRUE && \
		tmp->philosopher->n_diner == 0)
		{
			printf("%ld %d ate all\n", tmp->philosopher->finish_eat_time, \
			tmp->philosopher->philo_id);
			return ((void *)tmp);
		}
		sem_post(data->output);
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

	pthread_create(&simulation, NULL, (void *)controller, (t_data *)(data));
	pthread_join(simulation, (void *)&status);
	sem_destroy(data->fork);
	sem_destroy(data->output);
	sem_destroy(data->s_status);
}
