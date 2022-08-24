/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointertohexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:00:39 by dpaulino          #+#    #+#             */
/*   Updated: 2022/03/27 16:00:39 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdint.h>

static int	ptrlenghtcount(uintptr_t arg, int counter)
{
	counter = 0;
	while (arg > 0)
	{
		arg = arg / 16;
		counter++;
	}
	return (counter);
}

static char	*ptrhexastring(unsigned int i, char *tmp, uintptr_t arg)
{
	unsigned int	remainder;

	tmp[i] = '\0';
	while (i > 0)
	{
		remainder = arg % 16;
		if (remainder > 9)
		{
			tmp[i - 1] = remainder + 87;
		}
		if (remainder <= 9)
		{
			tmp[i - 1] = remainder + '0';
		}
		arg = arg / 16;
		i--;
	}
	return (tmp);
}

static int	ft_ptrhexaconvert(uintptr_t arg)
{
	unsigned int	arglenght;
	char			*tmp;

	if (arg == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (arg < 0)
	{
		arg = arg * -1;
		arglenght = ptrlenghtcount(arg, arglenght) + 1;
		tmp = malloc(sizeof(char) * arglenght + 1);
		tmp = ptrhexastring(arglenght, tmp, arg);
		tmp[0] = '-';
		ft_putstr_fd(tmp, 1);
		free(tmp);
		return (arglenght);
	}
	arglenght = ptrlenghtcount(arg, arglenght);
	tmp = malloc(sizeof(char) * arglenght + 1);
	tmp = ptrhexastring(arglenght, tmp, arg);
	ft_putstr_fd(tmp, 1);
	free(tmp);
	return (arglenght);
}

int	ft_pointertohexa(unsigned long arg)
{
	unsigned int	arglenght;

	arglenght = 0;
	arglenght += ft_putstr("0x");
	if (arg == 0)
	{
		ft_putchar_fd('0', 1);
		arglenght++;
	}
	else
	{
		arglenght += ft_ptrhexaconvert(arg);
	}
	return (arglenght);
}
