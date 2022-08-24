/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_first_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gameoverstation <dpaulino@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:31:57 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/03 03:26:09 by gameoverstation  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	del_first_elem(t_list **lst)
{
	t_list	*current;

	if ((*lst)->next != NULL)
	{
		current = (*lst)->next;
		free(*lst);
		*lst = current;
	}
	else
	{
		free(*lst);
		*lst = NULL;
	}
}
