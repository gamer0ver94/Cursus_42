/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:12:40 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/24 09:38:50 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_exit(t_data	*data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	data->exit.amount = 0;
	while (data->map.map[row])
	{
		while (data->map.map[row][col])
		{
			if (data->map.map[row][col] == 'E')
				data->exit.amount++;
			col++;
		}
		row++;
		col = 0;
	}
	if (data->exit.amount == 0)
		check_errors(data, 6);
	if (data->exit.amount > 1)
		check_errors(data, 3);
}
