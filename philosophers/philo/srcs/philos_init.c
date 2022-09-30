/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:49:25 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/29 21:58:26 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philos_init(t_table *table, t_info *info)
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
		tmp = tmp->right;
		i--;
		j++;
	}
	return (0);
}
