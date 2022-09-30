/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:59:06 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/29 22:08:05 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	wait_threads(t_table *table, t_info *info)
{
	t_table	*tmp;
	int		i;

	i = info->n_philos;
	tmp = table;
	while (i > 0)
	{
		pthread_join(tmp->philosopher->thread_id, NULL);
		i--;
		tmp = tmp->right;
	}
	return (0);
}

int	mutex_init(t_table *table, t_info *info)
{
	t_table	*tmp;
	int		i;

	tmp = table;
	i = info->n_philos;
	while (i > 0)
	{
		pthread_mutex_init(&tmp->philosopher->fork, NULL);
		tmp = tmp->right;
		i--;
	}
	return (0);
}

int	threads_init(t_table *table, t_info *info)
{
	t_table	*tmp;
	int		i;

	tmp = table;
	i = info->n_philos;
	while (i > 0)
	{
		if (pthread_create(&tmp->philosopher->thread_id, NULL, \
				(void *)start, (t_table *)(tmp)) != 0)
			printf("error\n");
		tmp = tmp->right;
		i--;
	}
	return (0);
}
