/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:34:36 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/06 23:00:54 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	get_commands(char **split, t_command **prompt)
{
	int		i;
	int		j;
	char	**tmp;
	char	**tmp_2;

	// tmp_2 = NULL;
	// tmp = NULL;
	j = 0;
	i = 0;
	(*prompt)->cmd = ft_strdup(split[i]);
	(*prompt)->argc = ft_array_size(split);
	(*prompt)->argv = malloc(sizeof(char *) * (*prompt)->argc + 1);
	while (split && split[i])
	{
			(*prompt)->argv[j] = ft_strdup(split[i]);
			free(split[i]);
			j++;
			i++;
	}
	free(split[i]);
	free(split);
	(*prompt)->argv[j] = NULL;
}

void split_buffer(char **args, char *buffer)
{
	int i;
	int	j;
	int lock;
	int l;

	l = 0;
	lock = 0;
	j = 0;
	i = 0;
	args[i] = malloc(sizeof(char *) * 100);
	while (buffer[l] != NULL)
	{
		if (buffer[l] == '\"' && lock != 2)
		{
			lock++;
			if (lock == 2)
				lock = 0;
		}
		else if (buffer[l] == ' ' && lock != 1)
		{
			i++;
			j = 0;
			args[i] = malloc(sizeof(char) * 100);
			while(buffer[l] && buffer[l + 1] == ' ')
			{
				l++;
			}
		}
		else if (buffer[l] == ' ' && lock == 1)
		{
			args[i][j] = buffer[l];
			j++;
		}
		else
		{
			args[i][j] = buffer[l];
			j++;
		}
		l++;
	}
	if(lock == 1)
	{
		args[i] = NULL;
		free(args[i]);
		printf("double quotes not closed");
		//open a new prompt
		while (1)
			readline("> ");
	}
	// args[j] = NULL;
}


int	parse_buffer(char *buffer, t_command **prompt, char **envp)
{
	char **args;
	int		i;

	i = 0;
	args = malloc(sizeof(char *) * 1000);
	if (find_char(buffer, '|'))
	{
		args = ft_split(buffer, '|');
		return (1);
	}
	else
	{
		split_buffer(args, buffer);
		get_commands(args, prompt);
	}
	return (0);
}
