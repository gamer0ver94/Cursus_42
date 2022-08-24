/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:11:06 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/09 13:02:52 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		bin_lenght;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	if (error_handler(argc, argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	create_stack(&stack_a, argv, argc);
	bin_lenght = ft_strlen((char *)stack_a->content);
	if (sort_verification(&stack_a, ft_lstsize(stack_a)) == 0)
		return (0);
	if (ft_lstsize(stack_a) > 5)
		sort_big_num(&stack_a, &stack_b, bin_lenght);
	else
		sort_small_num(&stack_a, &stack_b);
	return (0);
}
