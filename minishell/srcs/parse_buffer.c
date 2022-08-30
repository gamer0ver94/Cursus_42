/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:34:36 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/30 13:32:02 by dpaulino         ###   ########.fr       */
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
	int	j;

	j = 0;
	i = 1;
	(*prompt)->cmd = ft_strdup(split[0]);
	(*prompt)->argc = ft_array_size(split - 1);
	(*prompt)->argv = malloc(sizeof(char *) * (*prompt)->argc + 1);
	while (split && split[i])
	{
		(*prompt)->argv[j] = ft_strdup(split[i]);
		j++;
		i++;
	}
	(*prompt)->argv[j] = NULL;
}
//split and get struct with right values
int	parse_buffer(char *buffer, t_command **prompt)
{
	char **split;

	if (is_pipe(buffer))
	{
		split = ft_split(buffer, '|');
	}
	else
	{
		split = ft_split(buffer, ' ');
		get_commands(split, prompt);
	}
	return (0);
}
