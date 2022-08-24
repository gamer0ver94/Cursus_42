/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_enemys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:59:12 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/10 14:17:10 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_enemys(t_data *data)
{
	int	row;
	int	col;
	int	enemys;

	enemys = 0;
	row = 0;
	col = 0;
	while (data->map.map[row])
	{
		while (data->map.map[row][col])
		{
			if (data->map.map[row][col] == 'M')
				enemys++;
			col++;
		}
		row++;
		col = 0;
	}
	return (enemys);
}
