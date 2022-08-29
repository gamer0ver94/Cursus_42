/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:07:34 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/29 12:08:40 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	logo(void)
{
	int		fd;
	char	*logo;

	logo = (char *)ft_calloc(700, sizeof(char *));
	fd = open("logo.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (read(fd, logo, 1))
		printf("%s", logo);
	close(fd);
	free((char *)logo);
	return (0);
}
