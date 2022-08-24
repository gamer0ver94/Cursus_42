/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gameoverstation <dpaulino@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:49:54 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/06/13 01:25:05 by gameoverstation  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	coin_exit(t_data *data, int row, int col)
{
	if (data->map.map[row][col] == 'C')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->coin.img.start, (1920 / 2) - \
			((data->map.width / 2) * IMG_SIZE) + \
			(IMG_SIZE * col), (1080 / 2) - \
			((data->map.height / 2) * IMG_SIZE) + (row * IMG_SIZE));
	if (data->map.map[row][col] == 'E')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->exit.img.start, (1920 / 2) - \
			((data->map.width / 2) * IMG_SIZE) + \
			(IMG_SIZE * col), (1080 / 2) - \
			((data->map.height / 2) * IMG_SIZE) + (row * IMG_SIZE));
}

void	wall_floor(t_data *data, int row, int col)
{
	if (data->map.map[row][col] == '1')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->wall.img.start, (1920 / 2) - \
			((data->map.width / 2) * IMG_SIZE) + \
			(IMG_SIZE * col), (1080 / 2) - \
			((data->map.height / 2) * IMG_SIZE) + (row * IMG_SIZE));
	if (data->map.map[row][col] == '0')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->floor.img.start, (1920 / 2) - \
			((data->map.width / 2) * IMG_SIZE) + \
			(IMG_SIZE * col), (1080 / 2) - \
			((data->map.height / 2) * IMG_SIZE) + (row * IMG_SIZE));
}

void	players_enemy(t_data *data, int row, int col)
{
	if (data->map.map[row][col] == 'P')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->player.img.start, (1920 / 2) - \
			((data->map.width / 2) * IMG_SIZE) + \
			(IMG_SIZE * col), (1080 / 2) - \
			((data->map.height / 2) * IMG_SIZE) + (row * IMG_SIZE));
	if (data->map.map[row][col] == 'L')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->player2.img.start, (1920 / 2) - \
			((data->map.width / 2) * IMG_SIZE) + \
			(IMG_SIZE * col), (1080 / 2) - \
			((data->map.height / 2) * IMG_SIZE) + (row * IMG_SIZE));
	if (data->map.map[row][col] == 'M')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->enemy.img.start, (1920 / 2) - \
			((data->map.width / 2) * IMG_SIZE) + \
			(IMG_SIZE * col), (1080 / 2) - \
			((data->map.height / 2) * IMG_SIZE) + (row * IMG_SIZE));
}

void	map_update(t_data *data, int row, int col)
{
	wall_floor(data, row, col);
	players_enemy(data, row, col);
	coin_exit(data, row, col);
}
