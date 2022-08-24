/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:49:14 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/24 09:47:31 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_coins(t_data	*data)
{
	int	coins;
	int	row;
	int	col;

	coins = 0;
	row = 0;
	col = 0;
	while (data->map.map[row])
	{
		while (data->map.map[row][col])
		{
			if (data->map.map[row][col] == 'C')
			{
				if (!check_path_to_coins(data, row, col))
					check_errors(data, 10);
				coins++;
			}
			col++;
		}
		row++;
		col = 0;
	}
	if (coins == 0)
		check_errors(data, 8);
	return (coins);
}
