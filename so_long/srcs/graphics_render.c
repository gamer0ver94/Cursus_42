/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:07:01 by gameoversta       #+#    #+#             */
/*   Updated: 2022/09/01 16:16:19 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_constructor(t_data *data, int row, int col)
{
	if (data->menu.status == ON)
	{
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->menu.img.start, 0, 0);
		data->menu.status = WAIT;
	}
	if (data->menu.status == SELECTED)
	{
		if (data->map.width > 34 || data->map.height > 27)
			map_update2(data, row, col);
		else
			map_update(data, row, col);
	}
}

int	time_out(int time, t_data *data)
{
	time++;
	if (time == ENEMY_SPEED)
	{
		enemy_moves(data);
		time = 0;
	}
	return (time);
}

int	graphics_render(t_data *data)
{
	int			row;
	int			col;
	static int	time;

	row = 0;
	col = 0;
	if (check_enemy(data) == 0 && data->menu.status == SELECTED)
		time = time_out(time, data);
	while (data->map.map[row])
	{
		while (data->map.map[row][col])
		{
			map_constructor(data, row, col);
			col++;
		}
			row++;
			col = 0;
	}
	gameover(data);
	return (0);
}
