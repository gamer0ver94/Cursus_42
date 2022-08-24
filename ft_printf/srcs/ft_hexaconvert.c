/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaconvert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:00:21 by dpaulino          #+#    #+#             */
/*   Updated: 2022/03/27 16:00:21 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	lenghtcount(unsigned int arg, unsigned int counter)
{
	counter = 0;
	while (arg > 0)
	{
		arg = arg / 16;
		counter++;
	}
	return (counter);
}

char	*hexastring(int i, char *tmp, unsigned int arg, char format)
{
	unsigned int	remainder;

	tmp[i] = '\0';
	while (i > 0)
	{
		remainder = arg % 16;
		if (remainder > 9)
		{
			if (format == 'x')
				tmp[i - 1] = remainder + 87;
			else
				tmp[i - 1] = remainder + 55;
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

int	ft_hexaconvert(unsigned int arg, char format)
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
		arglenght = lenghtcount(arg, arglenght) + 1;
		tmp = malloc(sizeof(char) * arglenght + 1);
		tmp = hexastring(arglenght, tmp, arg, format);
		tmp[0] = '-';
		ft_putstr_fd(tmp, 1);
		free(tmp);
		return (arglenght);
	}
	arglenght = lenghtcount(arg, arglenght);
	tmp = malloc(sizeof(char) * arglenght + 1);
	tmp = hexastring(arglenght, tmp, arg, format);
	ft_putstr_fd(tmp, 1);
	free(tmp);
	return (arglenght);
}
