/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:20:52 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/10 14:09:45 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	enemy_move_up(t_data	*data)
{
	if (data->map.map[data->enemy.row - 1][data->enemy.col] != '1'
		&& data->map.map[data->enemy.row - 1][data->enemy.col] != 'E'
		&& data->map.map[data->enemy.row - 1][data->enemy.col] != 'C')
	{
		data->map.map[data->enemy.row][data->enemy.col] = '0';
		data->map.map[data->enemy.row -1][data->enemy.col] = 'M';
		data->enemy.row --;
		data->enemy.img.start = mlx_xpm_file_to_image(data->mlx,
				ENEMYUP, &data->enemy.img.width, &data->enemy.img.height);
		return (0);
	}
	data->enemy.img.start = mlx_xpm_file_to_image(data->mlx,
			ENEMYUPMAD, &data->enemy.img.width, &data->enemy.img.height);
	return (1);
}

int	enemy_move_down(t_data	*data)
{
	if (data->map.map[data->enemy.row + 1][data->enemy.col] != '1'
			&& data->map.map[data->enemy.row + 1][data->enemy.col] != 'E'
			&& data->map.map[data->enemy.row + 1][data->enemy.col] != 'C')
	{
		data->map.map[data->enemy.row][data->enemy.col] = '0';
		data->map.map[data->enemy.row + 1][data->enemy.col] = 'M';
		data->enemy.row ++;
		data->enemy.img.start = mlx_xpm_file_to_image(data->mlx,
				ENEMYDOWN, &data->enemy.img.width, &data->enemy.img.height);
		return (0);
	}
	data->enemy.img.start = mlx_xpm_file_to_image(data->mlx,
			ENEMYDOWNMAD, &data->enemy.img.width, &data->enemy.img.height);
	return (1);
}

int	enemy_move_left(t_data	*data)
{
	if (data->map.map[data->enemy.row][data->enemy.col - 1] != '1'
		&& data->map.map[data->enemy.row][data->enemy.col - 1] != 'E'
		&& data->map.map[data->enemy.row][data->enemy.col - 1] != 'C')
	{
		data->map.map[data->enemy.row][data->enemy.col] = '0';
		data->map.map[data->enemy.row][data->enemy.col - 1] = 'M';
		data->enemy.col--;
		data->enemy.img.start = mlx_xpm_file_to_image(data->mlx,
				ENEMYLEFT, &data->enemy.img.width, &data->enemy.img.height);
		return (0);
	}
	data->enemy.img.start = mlx_xpm_file_to_image(data->mlx,
			ENEMYLEFTMAD, &data->enemy.img.width, &data->enemy.img.height);
	return (1);
}

int	enemy_move_right(t_data	*data)
{
	if (data->map.map[data->enemy.row][data->enemy.col + 1] != '1'
		&& data->map.map[data->enemy.row][data->enemy.col + 1] != 'E'
		&& data->map.map[data->enemy.row][data->enemy.col + 1] != 'C')
	{
		data->map.map[data->enemy.row][data->enemy.col] = '0';
		data->map.map[data->enemy.row][data->enemy.col + 1] = 'M';
		data->enemy.col++;
		data->enemy.img.start = mlx_xpm_file_to_image(data->mlx,
				ENEMYRIGHT, &data->enemy.img.width, &data->enemy.img.height);
		return (0);
	}
	data->enemy.img.start = mlx_xpm_file_to_image(data->mlx,
			ENEMYRIGHTMAD, &data->enemy.img.width, &data->enemy.img.height);
	return (1);
}

int	enemy_moves(t_data *data)
{
	if (data->enemy.row > data->player.row)
		enemy_move_up(data);
	else if (data->enemy.row < data->player.row)
		enemy_move_down(data);
	else if (data->enemy.col > data->player.col)
		enemy_move_left(data);
	else if (data->enemy.col < data->player.col)
		enemy_move_right(data);
	enemy_position(data);
	return (0);
}
