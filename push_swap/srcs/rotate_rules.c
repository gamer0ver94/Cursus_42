/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:14:17 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/09 13:00:32 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next->next = NULL;
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rotate_rules(t_list **stack_a, t_list **stack_b, char *rule)
{
	if (rule[0] == 'r' && rule[1] == 'a')
	{
		printf("ra\n");
		ra(stack_a);
	}
	if (rule[0] == 'r' && rule[1] == 'b')
	{
		printf("rb\n");
		rb(stack_b);
	}
	if (rule[0] == 'r' && rule[1] == 'r')
	{
		printf("----rr----\n");
		rr(stack_a, stack_b);
	}
}
