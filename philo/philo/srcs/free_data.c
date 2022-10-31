/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 03:05:09 by dpaulino          #+#    #+#             */
/*   Updated: 2022/11/01 00:02:06 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_data(t_data *data)
{
	t_table		*table;
	t_table		*tmp;
	int			i;

	i = data->info->n_philos;
	table = data->table;
	while (i > 0)
	{
		pthread_mutex_destroy(table->philosopher->fork);
		free(table->philosopher->fork);
		free(table->philosopher);
		tmp = table;
		table = table->right;
		free(tmp);
		i--;
	}
	free(data->output);
	free(data->s_status);
	free(data->info);
	free(data);
}
