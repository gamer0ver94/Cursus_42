/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 03:05:09 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/25 11:25:34 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    free_data(t_data *data)
{
	t_table	*table;
	t_table	*tmp;
	int		i;

	i = data->info->n_philos;
	table = data->table;
	tmp = table->right;
	while (i > 0)
	{
		free(&table->philosopher->thread_id);
		free(table);
		table = tmp;
		tmp = table->right;
	}
	free(data);
}
