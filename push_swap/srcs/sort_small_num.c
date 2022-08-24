/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:00:41 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/09 13:00:54 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_small_num(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 3)
	{
		sort_three(stack_a, stack_b);
	}
	if (ft_lstsize(*stack_a) == 2)
		swap_rules(stack_a, stack_b, "sa");
	if (ft_lstsize(*stack_a) == 5)
		sort_helper(stack_a, stack_b, 2);
	if (ft_lstsize(*stack_a) == 4)
		sort_helper(stack_a, stack_b, 1);
}
