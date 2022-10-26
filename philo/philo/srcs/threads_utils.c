/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:59:06 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/26 11:19:14 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	mutex_init(t_table *table, t_info *info)
{
	t_table	*tmp;
	int		i;

	tmp = table;
	i = info->n_philos;
	while (i > 0)
	{
		pthread_mutex_init(&tmp->philosopher->fork, NULL);
		pthread_mutex_init(&tmp->philosopher->is_eating2, NULL);
		tmp = tmp->right;
		i--;
	}
	return (0);
}

int	threads_init(t_data *data)
{
	t_table	*tmp;
	int		i;

	tmp = data->table;
	i = data->info->n_philos;
	data->info->starting_time = get_time();
	while (i > 0)
	{
		tmp->philosopher->info->starting_time = data->info->starting_time;
		if (pthread_create(&tmp->philosopher->thread_id, NULL, \
				(void *)start, (t_data *)(data)) != 0)
			printf("error\n");
		if (pthread_detach(tmp->philosopher->thread_id) != 0)
			printf("error detaching\n");
		tmp->philosopher->last_meal = time_update(data->info->starting_time);
		tmp = tmp->right;
		i--;
	}
	return (0);
}
