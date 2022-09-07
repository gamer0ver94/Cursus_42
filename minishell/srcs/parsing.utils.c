/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:30:06 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/07 17:28:09 by dpaulino         ###   ########.fr       */
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

void replace_dolar(char **args, char **envp)
{
	int	i;
	int	j;
	int g;
	int h;
	char *tmp;

	tmp = ft_calloc(50, sizeof(char));
	g = 1;
	(void)envp;
	j = 0;
	i = 0;
	h = 0;
	while (args[i])
	{
		while (args[i][j])
		{
			if (args[i][j] == '$')
			{
				while (args[i][j + g] && args[i][j + g] != ' ')
				{
					tmp[h] = args[i][j + g];
					g++;
					h++;
				}
				tmp[h] = '\0';
				if (!ft_strncmp(tmp, "USER", ft_strlen(tmp)))
					args[i] = ft_strdup("USER");
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
