/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:49:54 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/09/01 16:06:54 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	coin_exit2(t_data *data, int row, int col)
{
	if (data->map.map[row][col] == 'C')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->coin.img.start, col * IMG_SIZE, row * IMG_SIZE + 30);
	if (data->map.map[row][col] == 'E')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->exit.img.start, col * IMG_SIZE, row * IMG_SIZE + 30);
}

void	wall_floor2(t_data *data, int row, int col)
{
	if (data->map.map[row][col] == '1')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->wall.img.start, col * IMG_SIZE, row * IMG_SIZE + 30);
	if (data->map.map[row][col] == '0')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->floor.img.start, col * IMG_SIZE, row * IMG_SIZE + 30);
}

void	players_enemy2(t_data *data, int row, int col)
{
	if (data->map.map[row][col] == 'P')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->player.img.start, col * IMG_SIZE, row * IMG_SIZE + 30);
	if (data->map.map[row][col] == 'L')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->player2.img.start, col * IMG_SIZE, row * IMG_SIZE + 30);
	if (data->map.map[row][col] == 'M')
		mlx_put_image_to_window(data->mlx, data->window.start,
			data->enemy.img.start, col * IMG_SIZE, row * IMG_SIZE + 30);
}

void	map_update2(t_data *data, int row, int col)
{
	wall_floor2(data, row, col);
	players_enemy2(data, row, col);
	coin_exit2(data, row, col);
}
