/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:34:03 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/17 16:21:21 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_width(char *argv)
{
	int		fd;
	char	*line;
	int		i;
	int		width;

	width = 0;
	i = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while ((line[width] && line[width] != '\n'))
		width++;
	while (line != NULL)
	{
		while ((line[i] && line[i] != '\n') && (line[i] && line[i] != '\0'))
			i++;
		if (i != width)
			return (1);
		i = 0;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (width);
}

void	update_map(t_data *data, char *argv)
{
	int		fd;
	char	*line;
	int		i;

	data->map.map = calloc(data->map.height, sizeof(char *) + 1);
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		data->map.map[i] = ft_calloc(data->map.width, sizeof(char) + 1);
		ft_strlcpy(data->map.map[i], line, (size_t)data->map.width + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

void	read_map(t_data *data, char *argv)
{
	int		fd;
	char	*line;

	data->map.width = map_width(argv);
	if (data->map.width == 1)
	{
		check_errors(data, 3);
	}
	data->map.height = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	update_map(data, argv);
}
