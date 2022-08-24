/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:48:19 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/08 13:01:13 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*filter_args(char **argv, int *array, int size)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(argv[1], ' ');
	while (tmp[i])
		i++;
	array = malloc(sizeof(int) * i);
	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (array);
}

int	*parse_args(char **argv, int argc)
{
	int	*array;
	int	i;

	i = 1;
	array = malloc(sizeof(int) * argc - 1);
	while (i < argc)
	{
		array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (array);
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	tmp;
	int	j;
	int	*sorted_array;

	sorted_array = cpy_array(array, size);
	j = 0;
	i = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (sorted_array[i] < sorted_array[j])
			{
				tmp = sorted_array[i];
				sorted_array[i] = sorted_array[j];
				sorted_array[j] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (sorted_array);
}

int	*transform_array(int *array, int size)
{
	int		*sorted_array;
	int		*new_array;
	int		i;
	int		index;

	i = 0;
	index = 0;
	sorted_array = sort_array(array, size);
	new_array = malloc(sizeof(int) * size);
	while (i < size)
	{
		while (array[i] != sorted_array[index])
		{
			index++;
		}
		new_array[i] = index;
		index = 0;
		i++;
	}
	free (array);
	free (sorted_array);
	return (new_array);
}

void	create_stack(t_list **stack_a, char **argv, int argc)
{
	int		*array;
	char	**bin;
	int		size;
	int		i;

	i = -1;
	array = NULL;
	if (argc == 2)
	{
		size = get_args_size(argv);
		array = filter_args(argv, array, size);
		array = transform_array(array, size);
		bin = convert_to_binary(array, size);
	}
	else
	{
		size = argc - 1;
		array = parse_args(argv, argc);
		array = transform_array(array, size);
		bin = convert_to_binary(array, size);
	}
	while (++i < size)
		ft_lstadd_back(stack_a, ft_lstnew(bin[i]));
}
