/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_initialization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gameoverstation <dpaulino@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:46:37 by dpaulino          #+#    #+#             */
/*   Updated: 2022/06/16 13:45:02 by gameoverstation  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
//initialize struct values
void	setup_map_objs(t_data *data)
{
	data->wall.img.start = mlx_xpm_file_to_image(data->mlx, WATER,
			&data->wall.img.width, &data->wall.img.height);
	data->floor.img.start = mlx_xpm_file_to_image(data->mlx, SAND,
			&data->floor.img.width, &data->floor.img.height);
	data->coin.img.start = mlx_xpm_file_to_image(data->mlx, COIN,
			&data->coin.img.width, &data->coin.img.height);
}

void	setup_menu(t_data *data)
{
	data->effect_1.img.start = mlx_xpm_file_to_image(data->mlx, EFFECT_1,
			&data->effect_1.img.width, &data->effect_1.img.height);
	data->effect_2.img.start = mlx_xpm_file_to_image(data->mlx, EFFECT_2,
			&data->effect_2.img.width, &data->effect_2.img.height);
	data->menu.img.start = mlx_xpm_file_to_image(data->mlx, BGSP,
			&data->menu.img.height, &data->menu.img.width);
	data->game_menu.img.start = mlx_xpm_file_to_image(data->mlx, GAME_MENU,
			&data->game_menu.img.width, &data->game_menu.img.height);
	data->exit.img.start = mlx_xpm_file_to_image(data->mlx, EXIT1,
			&data->exit.img.width, &data->exit.img.height);
	data->menu.status = ON;
	data->menu.sp = ON;
	data->menu.mp = OFF;
	data->menu.quit = OFF;
}

void	s_initialization(t_data *data)
{
	data->mlx = mlx_init();
	setup_menu(data);
	setup_map_objs(data);
	data->player.img.start = mlx_xpm_file_to_image(data->mlx, PLAYERDOWN,
			&data->player.img.width, &data->player.img.height);
	if (check_enemy(data) == 0)
	{
		data->enemy.img.start = mlx_xpm_file_to_image(data->mlx, ENEMYDOWN,
				&data->enemy.img.width, &data->enemy.img.height);
	}
	data->player.score = 0;
	data->player2.img.start = mlx_xpm_file_to_image(data->mlx, P2DOWN,
			&data->player.img.width, &data->player2.img.height);
	data->player.score_table.start = mlx_xpm_file_to_image(data->mlx, SCORE,
			&data->player.img.width, &data->player2.img.height);
}
