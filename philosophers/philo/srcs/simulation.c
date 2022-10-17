/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/17 14:00:47 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*start(void *args)
{
	t_table			*table;

	table = (t_table *)(args);
	eating_time(&table->left->philosopher->fork, &table->philosopher->fork, table, table->philosopher->info->starting_time);
	return (NULL);
}

void	*controller(void *args)
{
	t_data	*data;
	t_table	*tmp;
	
	data = (t_data *)(args);
	data->info->starting_time = get_time();
	threads_init(data);
	tmp = data->table;
	while (1)
	{
		if (time_update(data->info->starting_time) - tmp->philosopher->last_meal > data->info->time_to_die)
		{
			printf("death occured\n");
			printf("philosopher %d died at %ld\n", tmp->philosopher->philo_id, time_update(data->info->starting_time));
			exit(0);
		}
		tmp = tmp->right;
	}
}



void	simulation(t_data *data)
{
	pthread_t	simulation;

	pthread_create(&simulation, NULL, (void *)controller, (t_data *)(data));
	pthread_join(simulation, NULL);
}
