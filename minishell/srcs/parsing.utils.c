/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:30:06 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/07 12:23:31 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void init_parse_struct(t_parse *p)
{
	p->i = 0;
	p->j = 0;
	p->l = 0;
	p->lock = 0;
	p->lock_2 = 0;
}

int	ft_array_size(char **array) //5
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	find_char(char *buffer, char c)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void free_args(char **args)//2
{
	int i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
