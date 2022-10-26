/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/26 18:28:11 by dpaulino         ###   ########.fr       */
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
	while (1)
	{
		if (data->is_dead > 0)
		{
			pthread_mutex_lock(data->output);
			usleep(500);
			printf("philosopher %d died\n", data->is_dead);
			return ((void *)tmp);
		}
		tmp = tmp->right;
	}
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
	// if (data->info->eat_time_rules == TRUE && status->philosopher->n_diner == 0)
	// 	print_message(time_update(data->info->starting_time), \
	// 	status, "eat all meals", data);
	// else
	// 	print_message(time_update(data->info->starting_time), \
	// 	status, "died", data);
	pthread_mutex_destroy(data->output);
	pthread_mutex_destroy(data->s_status);
}
