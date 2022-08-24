/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:46:31 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/22 16:19:45 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		check_errors(&data, 2);
	if (argv[1])
	{
		data.map.path = argv[1];
		read_map(&data, argv[1]);
		check_map(&data);
		exit_position(&data);
		if (check_player(&data) == 1)
			check_errors(&data, 1);
		check_exit(&data);
		s_initialization(&data);
		player_position(&data);
		data.coin.amount = count_coins(&data);
		if (!check_path(&data, data.player.row, data.player.col))
			check_errors(&data, 9);
		if (check_enemy(&data) == 0)
			enemy_position(&data);
		new_window(&data);
		graphics_render(&data);
		keys_event(&data);
	}
	return (0);
}
