/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:17:05 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/19 10:21:39 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	gameover(t_data *data)
{
	if ((data->player.row == data->enemy.row \
			&& data->player.col == data->enemy.col) \
			|| (data->player2.row == data->enemy.row
			&& data->player2.col == data->enemy.col))
	{
		ft_putstr_fd("GAME OVER\nYOU LOST\n", 1);
		exit(0);
	}
	if (data->player2.row == data->enemy.row
		&& data->player2.col == data->enemy.col)
	{
		ft_putstr_fd("GAME OVER\nYOU LOST\n", 1);
		exit(0);
	}
}
