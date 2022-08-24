/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:19:05 by dpaulino          #+#    #+#             */
/*   Updated: 2022/03/09 14:59:47 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//review at the end
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pointer;

	pointer = malloc (nitems * size);
	if (!pointer)
	{
		return (NULL);
	}
	ft_bzero(pointer, nitems * size);
	return (pointer);
}
