/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:14:56 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/09/01 16:22:54 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	menu_enter_key(t_data *data)
{
	if (data->menu.sp == ON && data->menu.status == WAIT)
	{
		data->menu.status = SELECTED;
		mlx_clear_window(data->mlx, data->window.start);
		if (data->map.width < 34)
		{
			data->menu.img.start = mlx_xpm_file_to_image(data->mlx, BG, \
				&data->menu.img.width, &data->menu.img.height);
			mlx_put_image_to_window(data->mlx, data->window.start,
				data->menu.img.start, 0, 0);
		}
	}
	if (data->menu.mp == ON && data ->menu.status == WAIT)
	{
		data->player2.score++;
		data->map.map[data->player.row][data->player.col - 1] = 'L';
		player2_position(data);
		data->menu.status = SELECTED;
	}
	if (data->menu.quit == ON && data->menu.status == WAIT)
		exit(0);
}

void	menu_down_key(t_data *data)
{
	if (data->menu.mp == ON)
	{
		data->menu.img.start = mlx_xpm_file_to_image(data->mlx, BGQUIT,
				&data->menu.img.height, &data->menu.img.width);
		data->menu.status = ON;
		data->menu.quit = ON;
		data->menu.mp = OFF;
	}
	if (data->menu.sp == ON)
	{
		data->menu.img.start = mlx_xpm_file_to_image(data->mlx, BGMP,
				&data->menu.img.height, &data->menu.img.width);
		data->menu.status = ON;
		data->menu.mp = ON;
		data->menu.sp = OFF;
	}
}

void	menu_up_key(t_data *data)
{
	if (data->menu.mp == ON)
	{
		data->menu.img.start = mlx_xpm_file_to_image(data->mlx, BGSP,
				&data->menu.img.height, &data->menu.img.width);
		data->menu.status = ON;
		data->menu.sp = ON;
		data->menu.mp = OFF;
	}
	if (data->menu.quit == ON)
	{
		data->menu.img.start = mlx_xpm_file_to_image(data->mlx, BGMP,
				&data->menu.img.height, &data->menu.img.width);
		data->menu.status = ON;
		data->menu.mp = ON;
		data->menu.quit = OFF;
	}
}

void	menu_update(t_data *data, int key)
{
	if (key == S && data->menu.status == WAIT)
	{
		menu_down_key(data);
	}
	if (key == W && data->menu.status == 2)
	{
		menu_up_key(data);
	}
	if (key == ENTER)
	{
		menu_enter_key(data);
	}
}
