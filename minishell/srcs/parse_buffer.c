/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:34:36 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/29 17:16:20 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_command(char **tmp_buffer, t_command **prompt)
{
	(*prompt)->cmd = ft_strdup(tmp_buffer[0]);
}

void	get_args(char **tmp_buffer, t_command **prompt)
{
	int	i;

	i = 1;
	while(tmp_buffer[i])
		i++;
	(*prompt)->argv = malloc(sizeof(char *) * i);
	i = 1;
	while (tmp_buffer[i] && ft_strncmp(tmp_buffer[i], "|", 1) != 0)
	{
		(*prompt)->argv[i] = ft_strdup(tmp_buffer[i]);
		i++;
	}
}


int	parse_buffer(char *buffer, t_command **prompt)
{
	char	**tmp_buffer;
	int i = 0;
	tmp_buffer = ft_split(buffer, ' ');
	get_command(tmp_buffer,prompt);
	get_args(tmp_buffer, prompt);
	return (0);
}
