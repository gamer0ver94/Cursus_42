/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:59:06 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/27 14:51:58 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	semaphore_init(t_data *data)
{
	data->fork = malloc(sizeof(sem_t));
	data->output = malloc(sizeof(sem_t));
	data->s_status = malloc(sizeof(sem_t));
	if (sem_init(data->fork, 1, data->info->n_philos))
		printf("error initializing mutex\n");
	if (sem_init(data->output, 1, 1))
		printf("error initializing mutex\n");
	if (sem_init(data->s_status, 1, 1))
		printf("error initializing mutex\n");
	return (1);
}

int	processes_init(t_data *data)
{
	t_table	*tmp;
	int		i;

	tmp = data->table;
	i = data->info->n_philos;
	data->info->starting_time = get_time();
	while (i > 0)
	{
		tmp->philosopher->info->starting_time = data->info->starting_time;
		tmp->philosopher->last_meal = time_update(data->info->starting_time);
		tmp->philosopher->process_id = fork();
		if (tmp->philosopher->process_id == 0)
		{
			start(data);
		}
		tmp = tmp->right;
		i--;
	}
	return (0);
}
