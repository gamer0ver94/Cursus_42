/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_verification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:13:44 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/08 13:27:29 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	binary_to_int(char *bin)
{
	int	i;
	int	size;
	int	res;

	res = 0;
	i = 1;
	size = ft_strlen(bin) - 1;
	while (size >= 0)
	{
		if (bin[size] == '1')
			res += i;
		i *= 2;
		size--;
	}
	return (res);
}

int	sort_verification(t_list **list, int size)
{
	t_list	*current;

	current = *list;
	if (ft_lstsize(*list) != size)
		return (1);
	while (current->next)
	{
		if (current->next->content != NULL)
		{
			if (binary_to_int(current->content) > \
			binary_to_int(current->next->content))
				return (1);
		}
		current = current->next;
	}
	return (0);
}
