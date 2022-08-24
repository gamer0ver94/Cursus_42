/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:44:53 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/24 09:44:49 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	back_track_finder(t_data *data, char **map, int row, int col)
{
	if (map[row][col] == 'E')
		return (1);
	else if (map[row][col] == '0' || map[row][col] == 'C')
	{
		map[row][col] = 'X';
		if (row < data->map.height)
			if (back_track_finder(data, map, row + 1, col))
				return (1);
		if (row > 0)
			if (back_track_finder(data, map, row - 1, col))
				return (1);
		if (col < data->map.width)
			if (back_track_finder(data, map, row, col + 1))
				return (1);
		if (col > 0)
			if (back_track_finder(data, map, row, col - 1))
				return (1);
		map[row][col] = 'Y';
	}
	return (0);
}

int	check_path(t_data *data, int row, int col)
{
	char	**tmp_map;
	int		i;
	int		j;
	int		status;

	i = 0;
	j = 0;
	tmp_map = malloc(sizeof(char *) * data->map.height);
	while (data->map.map[i])
	{
		tmp_map[i] = malloc(sizeof(char) * data->map.width + 1);
		while (data->map.map[i][j])
		{
			tmp_map[i][j] = data->map.map[i][j];
			j++;
		}
		tmp_map[i][j] = '\0';
		j = 0;
		i++;
	}
	tmp_map[row][col] = '0';
	status = back_track_finder(data, tmp_map, row, col);
	i = 0;
	free(tmp_map);
	return (status);
}
