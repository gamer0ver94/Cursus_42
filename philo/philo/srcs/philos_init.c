/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:49:25 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/24 22:37:11 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philos_init(t_data *data, t_table *table, t_info *info)
{
	t_table	*tmp;
	int		i;
	int		j;

	j = 1;
	i = info->n_philos;
	tmp = table;
	while (i > 0)
	{
		tmp->philosopher = malloc(sizeof(t_philosopher));
		tmp->philosopher->n_diner = 0;
		tmp->philosopher->philo_id = j;
		tmp->philosopher->last_meal = 0;
		tmp->philosopher->death_time = 0;
		tmp->philosopher->n_diner = data->info->n_diner;
		tmp->philosopher->info = data->info;
		tmp->philosopher->is_eating = FALSE;
		tmp = tmp->right;
		i--;
		j++;
	}
	return (0);
}
