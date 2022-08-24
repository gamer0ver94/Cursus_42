/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:19:56 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/09 14:07:46 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	handle_max_int(char **param)
{
	int	i;

	i = 0;
	while (param[i])
	{
		if (ft_strncmp(param[i], "2147483647", ft_strlen(param[i])) > 0 \
			&& ft_strlen(param[i]) == 10)
			return (1);
		if (ft_strncmp(param[i], "-2147483648", ft_strlen(param[i])) > 0 \
			&& param[i][0] == '-' && ft_strlen(param[i]) == 11)
			return (1);
		if ((param[i][0] != '-' && ft_strlen(param[i]) > 10) \
			|| (param[i][0] == '-' && ft_strlen(param[i]) > 11))
			return (1);
		i++;
	}
	return (0);
}

int	check_param(char **param)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (param[i])
	{
		while (param[i][j])
		{
			if (j == 0 && param[i][j] == '-')
				j++;
			if ((param[i][j] < '0' || param[i][j] > '9'))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	if (i < 0)
		return (1);
	return (0);
}

int	count_param(char **param)
{
	int	i;

	i = 0;
	while (param[i])
		i++;
	return (i);
}

int	check_doubles(char **param)
{
	int	*lst;
	int	i;
	int	j;

	lst = malloc(sizeof(int) * count_param(param));
	i = 0;
	while (param[i])
	{
		lst[i] = ft_atoi(param[i]);
		i++;
	}
	i = 0;
	while (i < count_param(param))
	{
		j = i + 1;
		while (j < count_param(param))
		{
			if (lst[i] == lst[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_handler(int argc, char **argv)
{
	char	**param;

	if (argc == 2)
	{
		param = ft_split(argv[1], ' ');
		if (check_param(param) == 1 || check_doubles(param) == 1 \
		|| handle_max_int(param) == 1)
		{
			free(param);
			return (1);
		}
	}
	else
	{
		if (check_param(argv + 1) == 1 || check_doubles(argv + 1) == 1 \
		|| handle_max_int(argv + 1) == 1)
			return (1);
	}
	return (0);
}
