/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:30:06 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/05 15:13:59 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
char **parsing_utils(char *buffer)
{
	char **tmp;

	if (find_char(buffer, '<'))
	{
		tmp = ft_split(buffer, '<');
		return (tmp);
	}
	if (find_char(buffer, '<<'))
	{
		tmp = ft_split(buffer, '<<');
		return (tmp);
	}
	if (find_char(buffer, '>'))
	{
		tmp = ft_split(buffer, '>');
		return (tmp);
	}
	if (find_char(buffer, '>>'))
	{
		tmp = ft_split(buffer, '>>');
		return (tmp);
	}	
	if (find_char(buffer, '\"'))
	{
		tmp = ft_split(buffer, '\"');
		return (tmp);
	}
	if (find_char(buffer, '\''))
	{
		tmp = ft_split(buffer, '\'');
		return (tmp);
	}
	if (find_char(buffer, ' '))
	{
		tmp = ft_split(buffer, ' ');
		return (tmp);
	}
	return (0);
}
