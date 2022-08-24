/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:26:23 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/17 16:22:20 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_txt(t_data *data, int row, int col)
{
	if (data->map.map[row][col] != 'E' && \
			data->map.map[row][col] != 'M' && \
			data->map.map[row][col] != 'C' && \
			data->map.map[row][col] != '1' && \
			data->map.map[row][col] != '0' && \
			data->map.map[row][col] != 'P')
	{
		free(data->map.map);
		check_errors(data, 7);
	}
}

int	check_map(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (data->map.map[row])
	{
		while (data->map.map[row][col])
		{
			if (data->map.map[0][col] != '1'
				|| data->map.map[row][0] != '1'
				|| data->map.map[row][data->map.width - 1] != '1'
				|| data->map.map[data->map.height - 1][col] != '1')
				check_errors(data, 4);
			else
				check_txt(data, row, col);
			col++;
		}
		col = 0;
		row++;
	}
	data->enemy_amount = count_enemys(data);
	if (data->enemy_amount > 1)
		check_errors(data, 5);
	return (0);
}
