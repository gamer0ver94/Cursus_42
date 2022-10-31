/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/31 14:46:10 by dpaulino         ###   ########.fr       */
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
	routine(table, table->philosopher->info->starting_time, data);
	return (NULL);
}

int	*controller(void *args)
{
	t_data	*data;
	t_table	*table;

	data = (t_data *)(args);
	table = data->table;
	data->is_dead = FALSE;
	threads_init(data);
	while (!data->is_dead)
	{
		if (is_dead(table, data))
		{
			printf("%ld %d died\n", data->death_time, \
			data->is_dead);
			break ;
		}
		else if (data->info->eat_time_rules == TRUE && data->n_ate_all == 0)
			break ;
		table = table->right;
	}
	return (0);
}

void	simulation(t_data *data)
{
	pthread_t	simulation;

	data->is_dead = 0;
	data->n_ate_all = data->info->n_philos;
	data->death_time = 0;
	data->s_status = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->s_status, NULL);
	data->output = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->output, NULL);
	pthread_create(&simulation, NULL, (void *)controller, (t_data *)(data));
	pthread_join(simulation, NULL);
	pthread_mutex_unlock(data->output);
	pthread_mutex_destroy(data->output);
	pthread_mutex_destroy(data->s_status);
}
