/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:24:26 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/09 15:30:20 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	walk_on_coins(t_data *data, int key, int row, int col)
{
	if (key == W)
	{
		data->map.map[row][col] = '0';
		data->map.map[row - 1][col] = 'P';
	}
	if (key == S)
	{
		data->map.map[row][col] = '0';
		data->map.map[row + 1][col] = 'P';
	}
	if (key == A)
	{
		data->map.map[row][col] = '0';
		data->map.map[row][col - 1] = 'P';
	}
	if (key == D)
	{
		data->map.map[row][col] = '0';
		data->map.map[row][col + 1] = 'P';
	}
	data->coin.amount--;
}

void	walk_on_floor(t_data *data, int key, int row, int col)
{
	if (key == W)
	{
		data->map.map[row][col] = '0';
		data->map.map[row - 1][col] = 'P';
	}
	if (key == S)
	{
		data->map.map[row][col] = '0';
		data->map.map[row + 1][col] = 'P';
	}
	if (key == A)
	{
		data->map.map[row][col] = '0';
		data->map.map[row][col - 1] = 'P';
	}
	if (key == D)
	{
		data->map.map[row][col] = '0';
		data->map.map[row][col + 1] = 'P';
	}
}

void	move_vertical(t_data *data, int key, int row, int col)
{
	if (key == W)
	{
		if (data->map.map[row - 1][col] == '0')
			walk_on_floor(data, key, row, col);
		if (data->map.map[row - 1][col] == 'C')
			walk_on_coins(data, key, row, col);
				data->player.img.start = mlx_xpm_file_to_image(data->mlx,
				PLAYERUP,
				&data->player.img.width, &data->player.img.height);
	}
	if (key == S)
	{
		if (data->map.map[row + 1][col] == '0')
			walk_on_floor(data, key, row, col);
		if (data->map.map[row + 1][col] == 'C')
			walk_on_coins(data, key, row, col);
				data->player.img.start = mlx_xpm_file_to_image(data->mlx,
				PLAYERDOWN,
				&data->player.img.width, &data->player.img.height);
	}
}

void	move_horizontal(t_data *data, int key, int row, int col)
{
	if (key == A)
	{
		if (data->map.map[row][col - 1] == '0')
			walk_on_floor(data, key, row, col);
		if (data->map.map[row][col - 1] == 'C')
			walk_on_coins(data, key, row, col);
		data->player.img.start = mlx_xpm_file_to_image(data->mlx,
				PLAYERLEFT,
				&data->player.img.width, &data->player.img.height);
	}
	if (key == D)
	{
		if (data->map.map[row][col + 1] == '0')
			walk_on_floor(data, key, row, col);
		if (data->map.map[row][col + 1] == 'C')
			walk_on_coins(data, key, row, col);
				data->player.img.start = mlx_xpm_file_to_image(data->mlx,
				PLAYERRIGHT,
				&data->player.img.width, &data->player.img.height);
	}
}

void	player_move(t_data *data, int key)
{
	int	row;
	int	col;

	row = data->player.row;
	col = data->player.col;
	if (data->coin.amount == 0)
		data->exit.img.start = mlx_xpm_file_to_image(data->mlx,
				EXIT2, &data->coin.img.width, &data->coin.img.height);
	move_vertical(data, key, row, col);
	move_horizontal(data, key, row, col);
	exit_position(data);
	player_position(data);
}
