/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:01:25 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/01 16:05:44 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	generate_window(t_data *data)
{
	if (data->map.width > 34 || data->map.height > 27)
		new_window(data, data->map.width * IMG_SIZE, \
			data->map.height * IMG_SIZE);
	else
		new_window(data, WIN_WIDTH, WIN_HEIGHT);
}
