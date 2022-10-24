/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/24 12:39:36 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*start(void *args)
{
	t_data			*data;
	t_table			*table;

	data = (t_data *)(args);
	pthread_mutex_unlock(&data->sim_status);
	pthread_mutex_lock(&data->sim_status);
	table = data->table;
	data->table = data->table->right;
	pthread_mutex_unlock(&data->sim_status);
	eating_time(table, table->philosopher->info->starting_time, data);
	return (NULL);
}

t_table	*controller(void *args)
{
	t_data	*data;
	t_table	*tmp;

	data = (t_data *)(args);
	pthread_mutex_init(&data->sim_status, NULL);
	threads_init(data);
	tmp = data->table;
	pthread_mutex_lock(&data->sim_status);
	while (1)
	{
		if ((time_update(data->info->starting_time) - \
			tmp->philosopher->last_meal) > data->info->time_to_die && tmp->philosopher->is_eating == FALSE)
			{
				pthread_mutex_lock(&data->sim_status);
				return ((void *)tmp);
			}
		else if (tmp->philosopher->info->eat_time_rules == TRUE && tmp->philosopher->n_diner == 0)
		{
			pthread_mutex_lock(&data->sim_status);
			return ((void *)tmp);
		}
		tmp = tmp->right;
	}
}

void	simulation(t_data *data)
{
	pthread_t	simulation;
	t_table		*status;

	pthread_create(&simulation, NULL, (void *)controller, (t_data *)(data));
	pthread_join(simulation, (void *)&status);
	pthread_mutex_unlock(&data->sim_status);
	printf("%ld was the last meal\n", status->philosopher->last_meal);
	if (data->info->eat_time_rules == TRUE && status->philosopher->n_diner == 0)
		print_message(time_update(data->info->starting_time), status, "eat all meals");
	else
	{
		print_message(time_update(data->info->starting_time), status, "died  ");
	}
}
