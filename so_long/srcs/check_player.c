/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gameoverstation <dpaulino@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:16:02 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/06/16 01:56:55 by gameoverstation  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_player(t_data *data)
{
	int	x;
	int	y;

	data->player.n = 0;
	x = 0;
	y = 0;
	while (data->map.map[y])
	{
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'P')
			{
				data->player.n++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (data->player.n == 0 || data->player.n > 1)
		return (1);
	return (0);
}
