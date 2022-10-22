/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/22 15:55:27 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*start(void *args)
{
	t_table			*table;

	table = (t_table *)(args);
	eating_time(&table->left->philosopher->fork, &table->philosopher->fork, \
	table, table->philosopher->info->starting_time);
	return (NULL);
}

t_table	*controller(void *args)
{
	t_data	*data;
	t_table	*tmp;

	data = (t_data *)(args);
	threads_init(data);
	tmp = data->table;
	while (1)
	{
		if (tmp->philosopher->info->eat_time_rules == TRUE && pthread_mutex_lock(&tmp->philosopher->all_ate) != 0)
		{
			return ((void *)tmp);
		}
		else if ((time_update(data->info->starting_time) - \
			tmp->philosopher->last_meal) > data->info->time_to_die && pthread_mutex_lock(&tmp->philosopher->eating) == 0)
			return ((void *)tmp);
		else
		{
			pthread_mutex_unlock(&tmp->philosopher->all_ate);
			pthread_mutex_unlock(&tmp->philosopher->eating);
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
	printf("%ld was the last meal\n", status->philosopher->last_meal);
	if (data->info->eat_time_rules == TRUE && status->philosopher->n_diner == 0)
		print_message(time_update(data->info->starting_time), status, "eat all meals");
	else
	{
		printf("death occured\n");
		print_message(time_update(data->info->starting_time), status, "died  ");
	}
	pthread_mutex_unlock(&status->philosopher->eating);
}
