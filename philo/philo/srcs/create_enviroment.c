/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_enviroment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:00:19 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/23 20:08:05 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	create_enviroment(t_table *table, t_info *info)
{
	t_table	*tmp;
	t_table	*aux;
	int		i;
	int		j;

	tmp = table;
	i = info->n_philos;
	j = 1;
	while (i > 1)
	{
		tmp->right = malloc(sizeof(t_table));
		aux = tmp;
		tmp = tmp->right;
		tmp->left = aux;
		i--;
		j++;
	}
	aux = tmp;
	tmp->right = table;
	table->left = aux;
	return (0);
}