/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gameoverstation <dpaulino@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:45:56 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/06/12 23:45:58 by gameoverstation  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player2_position(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map.map[y])
	{
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'L')
			{
				data->player2.row = y;
				data->player2.col = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
