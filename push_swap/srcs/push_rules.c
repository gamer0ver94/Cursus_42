/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:14:00 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/07/12 16:48:53 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{	
	t_list	*tmp;

	tmp = *stack_a;
	if ((*stack_b) == NULL)
	{
		*stack_b = ft_lstnew(tmp->content);
	}
	else
	{
		ft_lstadd_front(stack_b, ft_lstnew(tmp->content));
	}
	del_first_elem(stack_a);
}

void	pa(t_list **stack_a, t_list **stack_b)
{	
	t_list	*tmp;

	tmp = *stack_b;
	if ((*stack_a) == NULL)
	{
		(*stack_a) = ft_lstnew(tmp->content);
	}
	else
	{
		ft_lstadd_front(stack_a, ft_lstnew(tmp->content));
	}
	del_first_elem(stack_b);
}

void	push_rules(t_list **stack_a, t_list **stack_b, char *rule)
{
	if (rule[0] == 'p' && rule[1] == 'a')
	{
		printf("pa\n");
		pa(stack_a, stack_b);
	}
	if (rule[0] == 'p' && rule[1] == 'b')
	{
		printf("pb\n");
		pb(stack_a, stack_b);
	}
}
