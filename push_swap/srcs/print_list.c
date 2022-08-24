/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:28:53 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/09 13:01:10 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_list *stack_a, t_list *stack_b)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = stack_a;
	list_b = stack_b;
	if (list_a != NULL)
	{
		printf("STACK A\n");
		while (list_a)
		{
			printf("%s\n", (char *)list_a->content);
			list_a = list_a->next;
		}
	}
	if (list_b != NULL)
	{
		printf("STACK B\n");
		while (list_b)
		{
			printf("%s\n", (char *)list_b->content);
			list_b = list_b->next;
		}
	}
	else
		printf("STACK B\nempty\n\n");
}
