/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:18:06 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/08 13:25:57 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_index(t_list **stack, int i)
{
	t_list	*tmp;
	char	*str;

	tmp = *stack;
	while (tmp)
	{
		str = ft_strdup((char *)tmp->content);
		if (str[ft_strlen(str) - i - 1] == '0')
		{
			free(str);
			return (1);
		}
		tmp = tmp->next;
	}
	free(str);
	return (0);
}

int	count_max_index(t_list *stack_a)
{
	int		i;
	t_list	*tmp;
	char	*str;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		str = ft_strdup((char *)tmp->content);
		while (str[i])
		{
			i++;
		}
		tmp = tmp->next;
	}
	free(str);
	return (i);
}

void	sort_big_num(t_list **stack_a, t_list **stack_b, int size)
{
	char	*tmp;
	int		i;
	int		j;
	int		d;

	d = ft_lstsize(*stack_a);
	j = -1;
	i = -1;
	while (++i < size)
	{
		while (++j < d)
		{
			tmp = ft_strdup((*stack_a)->content);
			if (tmp[(size - 1) - i] == '0')
				push_rules(stack_a, stack_b, "pb");
			if (tmp[(size - 1) - i] == '1')
				rotate_rules(stack_a, stack_b, "ra");
			free(tmp);
		}
		j = -1;
		while (*stack_b != NULL)
			push_rules(stack_a, stack_b, "pa");
	}
	free(tmp);
}
