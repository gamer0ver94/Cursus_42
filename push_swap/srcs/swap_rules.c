/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gameoverstation <dpaulino@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:14:22 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/03 11:57:11 by gameoverstation  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_list *stack_b)
{
	int	tmp;

	tmp = *(int *)stack_b->content;
	*(int *)stack_b->content = *(int *)stack_b->next->content;
	*(int *)stack_b->next->content = tmp;
}

void	sa(t_list *stack_a)
{
	int	tmp;

	tmp = *(int *)stack_a->content;
	*(int *)stack_a->content = *(int *)stack_a->next->content;
	*(int *)stack_a->next->content = tmp;
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	swap_rules(t_list **stack_a, t_list **stack_b, char *rule)
{
	if (rule[0] == 's' && rule[1] == 'a')
	{
		printf("sa\n");
		sa(*stack_a);
	}
	if (rule[0] == 's' && rule[1] == 'b')
	{
		printf("sb\n");
		sb(*stack_b);
	}
	if (rule[0] == 's' && rule[1] == 's')
	{
		printf("ss\n");
		ss(*stack_a, *stack_b);
	}
}
