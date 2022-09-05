/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:34:36 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/05 15:18:34 by dpaulino         ###   ########.fr       */
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
	char	**tmp;

	tmp = NULL;
	i = 0;
	(*prompt)->cmd = ft_strdup(split[0]);
	(*prompt)->argc = ft_array_size(split);
	(*prompt)->argv = malloc(sizeof(char *) * (*prompt)->argc + 1);
	while (split && split[i])
	{
		(*prompt)->argv[i] = ft_strdup(split[i]);
		i++;
	}
	(*prompt)->argv[i] = NULL;
}

char *single_string(char **split)
{
	int i;
	int j;
	char *tmp;
	i = 0;
	j = 0;
	while(split[i])
	{
		while (split[i][j])
		{
			
		}
	}
}

int	parse_buffer(char *buffer, t_command **prompt)
{
	char	**split;
	char *tmp;
	
	while (parsing_utils(buffer))
	{
		split = parsing_utils(buffer);
		tmp = single_string(buffer);
	}




	// if (find_char(buffer, '|'))
	// {
	// 	split = ft_split(buffer, '|');
	// 	return (1);
	// }
	// else
	// {
	// 	split = parsing_utils(buffer);
	// 	// split = ft_split(buffer, '\"');
	// 	if (split != NULL)
	// 		get_commands(split, prompt);
	// }
	return (0);
}
