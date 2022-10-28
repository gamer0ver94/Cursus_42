/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:59:06 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/28 12:38:13 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	semaphore_init(t_data *data)
{
	data->fork = malloc(sizeof(sem_t));
	data->output = malloc(sizeof(sem_t));
	data->s_status = malloc(sizeof(sem_t));
	data->fork = sem_open("fork", O_CREAT, 0644, data->info->n_philos);
	return (1);
}

int	processes_init(t_data *data)
{
	t_table	*tmp;
	int		i;
	pthread_t monitor;

	tmp = data->table;
	i = data->info->n_philos;
	data->info->starting_time = get_time();
	usleep(100);
	while (i > 0)
	{
		tmp->philosopher->info->starting_time = data->info->starting_time;
		tmp->philosopher->last_meal = time_update(data->info->starting_time);
		tmp->philosopher->process_id = fork();
		if (tmp->philosopher->process_id == 0)
		{
			pthread_create(&monitor, NULL, (void *)controller, (t_data *)(data));
			pthread_detach(monitor);
			start(data);
		}
		tmp = tmp->right;
		i--;
	}
	return (0);
}
