/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gameoverstation <dpaulino@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:47:05 by dpaulino          #+#    #+#             */
/*   Updated: 2022/06/16 02:12:06 by gameoverstation  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	new_window(t_data *data)
{
	data->window.start = mlx_new_window(data->mlx, WIN_WIDTH,
			WIN_HEIGHT, "Game");
}
