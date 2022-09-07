/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:34:36 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/07 12:28:16 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_commands(char **split, t_command **prompt)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	(*prompt)->cmd = ft_strdup(split[0]);
	(*prompt)->argc = ft_array_size(split);
	(*prompt)->argv = ft_calloc((*prompt)->argc + 1, sizeof(char *));
	while (split && split[i])
	{
			(*prompt)->argv[j] = ft_strdup(split[i]);
			j++;
			i++;
	}
	(*prompt)->argv[j] = NULL;
}

void split_buffer(char **args, char *buffer)
{
	t_parse p;

	init_parse_struct(&p);
	args[p.i] = ft_calloc(100, sizeof(char));
	while (buffer[p.l])
	{
		if (buffer[p.l] == '\"' && p.lock != 2)//open first quote
		{
			p.lock++;
			if (p.lock == 2)
				p.lock = 0;
		}
		else if (buffer[p.l] == ' ' && p.lock != 1) // if no quotes or quotes are closed then takes word as next argv
		{
			p.i++;
			p.j = 0;
			args[p.i] = ft_calloc(100, sizeof(char));
			while(buffer[p.l] && buffer[p.l + 1] == ' ')
				p.l++;
		}
		else if (buffer[p.l] == ' ' && p.lock == 1) // if quotes are open take space for the same argv
			args[p.i][p.j++] = buffer[p.l];
		else // no quotes open
			args[p.i][p.j++] = buffer[p.l];
		p.l++;
	}
}

int	parse_buffer(char *buffer, t_command **prompt)
{
	char **args;

	args = ft_calloc(100, sizeof(char *));
	if (!args)
	{
		free(args);
		return (1);
	}
	if (find_char(buffer, '|'))
	{
		args = ft_split(buffer, '|');
		return (1);
	}
	else
	{
		split_buffer(args, buffer);
		get_commands(args, prompt);
		free_args(args);
	}
	return (0);
}

	// if(p.lock == 1) //if quotes are open in the end of the parsing
	// {
	// 	args[p.i] = NULL;
	// 	free(args[p.i]);
	// 	printf("double quotes not closed\n");
	// 	//open a new prompt
	// 	while (1)
	// 		readline("> ");
	// }
	// args[p.j] = NULL;