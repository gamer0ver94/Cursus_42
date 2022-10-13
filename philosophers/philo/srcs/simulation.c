/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:07:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/13 10:06:06 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*start(void *args)
{
	t_table			*table;

	table = (t_table *)(args);
	eat(&table->left->philosopher->fork, &table->philosopher->fork, table);
	return (NULL);
}



void	simulation(t_table *table, t_info *info)
{
	struct timeval	current_time;
	long			initial_time;
	long			updated_time;
	int				i;
	t_table			*tmp;

	i = info->n_philos;
	gettimeofday(&current_time, NULL);
	initial_time = current_time.tv_sec;
	tmp = table;
	mutex_init(table, info);
	threads_init(table, info);
	while (1)
	{
		while(i > 0)
		{
			updated_time = time_update(initial_time);
			tmp->timestamp->time = updated_time;
			sleep (1);
			tmp = tmp->right;
			i--;
		}
		i = info->n_philos;
	}
	// wait_threads(table, info);
}
