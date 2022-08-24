/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:05:24 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/09 12:43:36 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

typedef struct s_var
{
	int	i;
	int	j;
	int	max;
}	t_var;

int	get_max_index(int *args, int size)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (i < size)
	{
		if (count_size(args[i]) > res)
			res = count_size(args[i]);
		i++;
	}
	return (res);
}

int	*cpy_array(int *array, int size)
{
	int	i;
	int	*new_array;

	i = 0;
	new_array = malloc(sizeof(int) * size);
	while (i < size)
	{
		new_array[i] = array[i];
		i++;
	}
	return (new_array);
}

int	get_args_size(char **argv)
{
	char	**tmp;
	int		i ;

	i = 0;
	tmp = ft_split(argv[1], ' ');
	while (tmp[i])
	{
		i++;
	}
	return (i);
}

int	count_size(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 2;
		count++;
	}
	return (count);
}

char	**convert_to_binary(int *args, int size)
{
	char	**bin;
	char	*tmp;
	t_var	var;

	var.i = -1;
	var.j = get_max_index(args, size);
	bin = ft_calloc(size + 1, sizeof(char *));
	while (++var.i < size)
	{
		var.max = var.j + 1;
		tmp = ft_calloc(var.max + 1, sizeof(char));
		while (args[var.i] > 0)
		{
			if (args[var.i] % 2 == 1)
				tmp[--var.max - 1] = '1';
			else
				tmp[--var.max - 1] = '0';
			args[var.i] = args[var.i] / 2;
		}
		while (--var.max > 0)
			tmp[var.max - 1] = '0';
		bin[var.i] = ft_strdup((char *)tmp);
	}
	return (bin);
}
