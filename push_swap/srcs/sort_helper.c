/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:53:08 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/09 12:55:57 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_num(t_list *stack_a)
{
	t_list	*tmp;
	int		res;

	tmp = stack_a;
	res = binary_to_int(tmp->content);
	while (tmp)
	{
		if (binary_to_int(tmp->content) < res)
			res = binary_to_int(tmp->content);
		tmp = tmp->next;
	}
	return (res);
}

int	find_max_num(t_list *stack_a)
{
	t_list	*tmp;
	int		res;

	tmp = stack_a;
	res = binary_to_int(tmp->content);
	while (tmp)
	{
		if (binary_to_int(tmp->content) > res)
			res = binary_to_int(tmp->content);
		tmp = tmp->next;
	}
	return (res);
}

int	smart_rotate(t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 1;
	while (binary_to_int((char *)tmp->content) != find_min_num(*stack_a))
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= 3)
		return (1);
	return (0);
}

void	sort_three(t_list **stack_a, t_list **stack_b)
{
	while (binary_to_int((*stack_a)->next->next->content) \
		!= find_max_num(*stack_a))
	{
		if (binary_to_int((*stack_a)->next->content) == find_max_num(*stack_a))
		{
			reverse_rules(stack_a, stack_b, "rra");
		}
		if (binary_to_int((*stack_a)->content) == find_max_num(*stack_a))
			rotate_rules(stack_a, stack_b, "ra");
	}
	if (binary_to_int((*stack_a)->content) > \
		binary_to_int((*stack_a)->next->content))
		swap_rules(stack_a, stack_b, "sa");
}

void	sort_helper(t_list **stack_a, t_list **stack_b, int n)
{
	while (ft_lstsize(*stack_b) != n)
	{
		if (binary_to_int((*stack_a)->content) == find_min_num(*stack_a))
			push_rules(stack_a, stack_b, "pb");
		else
		{
			if (smart_rotate(stack_a) == 1)
				rotate_rules(stack_a, stack_b, "ra");
			else
				reverse_rules(stack_a, stack_b, "rra");
		}
	}
	sort_three(stack_a, stack_b);
	while (*stack_b != NULL)
		push_rules(stack_a, stack_b, "pa");
}
