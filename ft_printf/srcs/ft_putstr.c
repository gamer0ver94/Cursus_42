/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:03:36 by dpaulino          #+#    #+#             */
/*   Updated: 2022/03/28 10:03:36 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *string)
{
	int	i;

	i = 0;
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (string[i])
	{
		write (1, &string[i], 1);
		i++;
	}
	return (i);
}
