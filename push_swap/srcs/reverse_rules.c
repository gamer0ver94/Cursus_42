/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:14:06 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/07/12 16:49:17 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next->next = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next->next = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	reverse_rules(t_list **stack_a, t_list **stack_b, char *rule)
{
	if (rule[0] == 'r' && rule[1] == 'r' && rule[2] == 'a')
	{
		printf("rra\n");
		rra(stack_a);
	}
	if (rule[0] == 'r' && rule[1] == 'r' && rule[2] == 'b')
	{
		printf("rrb\n");
		rrb(stack_b);
	}
	if (rule[0] == 'r' && rule[1] == 'r' && rule[2] == 'r')
	{
		printf("rrr\n");
		rrr(stack_a, stack_b);
	}
}
