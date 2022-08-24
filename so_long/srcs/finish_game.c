/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gameoverstation <dpaulino@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:51:07 by dpaulino          #+#    #+#             */
/*   Updated: 2022/06/16 01:55:40 by gameoverstation  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_exit(void)
{
	ft_putstr_fd("YOU WON\nWELL PLAYED\n", 1);
	exit(0);
}

void	finish_game(t_data *data, int key)
{
	int	row;
	int	col;
	int	coins;

	coins = data->coin.amount;
	row = data->player.row;
	col = data->player.col;
	if (key == W && data->map.map[row - 1][col] == 'E' && coins == 0)
	{
		print_exit();
	}
	if (key == S && data->map.map[row + 1][col] == 'E' && coins == 0)
	{
		print_exit();
	}
	if (key == A && data->map.map[row][col - 1] == 'E' && coins == 0)
	{
		print_exit();
	}
	if (key == D && data->map.map[row][col + 1] == 'E' && coins == 0)
	{
		print_exit();
	}
}
