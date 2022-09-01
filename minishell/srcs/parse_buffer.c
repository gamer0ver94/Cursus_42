/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:34:36 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/01 11:56:14 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//verify if pipe exists
int	is_pipe(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if(buffer[i] == '|')
			return(1);
		i++;
	}
	return (0);
}

int	ft_array_size(char **array)
{
	int	i;

	i = 0;
	while(array[i])
		i++;
	return (i);
}

void	get_commands(char **split, t_command **prompt)
{
	int	i;
	char **tmp;

	tmp = NULL;
	i = 0;
	(*prompt)->cmd = ft_strdup(split[0]);
	(*prompt)->argc = ft_array_size(split);
	(*prompt)->argv = malloc(sizeof(char *) * (*prompt)->argc + 1);
	while (split && split[i])
	{
		// if (split[i][0] == 34)
		(*prompt)->argv[i] = ft_strdup(split[i]);
		i++;
	}
	(*prompt)->argv[i] = NULL;
}
//split and get struct with right values
int	parse_buffer(char *buffer, t_command **prompt)
{
	char **split;

	if (is_pipe(buffer))
	{
		split = ft_split(buffer, '|');
		return (1);
	}
	else
	{
		split = ft_split(buffer, ' ');
		get_commands(split, prompt);
	}
	return (0);
}
