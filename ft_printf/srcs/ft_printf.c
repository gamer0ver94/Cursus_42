/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:16:45 by dpaulino          #+#    #+#             */
/*   Updated: 2022/03/20 14:16:45 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	formatidentifier(char str, va_list pa)
{
	int	arglenght;

	arglenght = 0;
	if (str == 'c')
	{
		ft_putchar_fd(va_arg(pa, int), 1);
		arglenght ++;
	}
	if (str == 's')
		arglenght += ft_putstr(va_arg(pa, char *));
	if (str == 'd' || str == 'i')
		arglenght += ft_writeitoa(va_arg(pa, int));
	if (str == 'p')
		arglenght += ft_pointertohexa(va_arg(pa, unsigned long));
	if (str == 'u')
		arglenght += ft_unsigneditoa(va_arg(pa, unsigned int));
	if (str == 'x' || str == 'X')
		arglenght += ft_hexaconvert(va_arg(pa, unsigned int), str);
	if (str == '%')
	{
		ft_putchar_fd('%', 1);
		arglenght++;
	}
	return (arglenght);
}

int	ft_printf(const char *str, ...)
{
	va_list	pa;
	int		i;
	int		arglenght;

	va_start(pa, str);
	arglenght = 0;
	i = 0;
	arglenght = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			arglenght += formatidentifier(str[i + 1], pa);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			arglenght++;
		}
		i++;
	}
	va_end(pa);
	return (arglenght);
}
