/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:08:35 by dpaulino          #+#    #+#             */
/*   Updated: 2022/03/20 14:08:35 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "../../libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_hexaconvert(unsigned int arg, char format);
int	ft_putstr(char *string);
int	ft_writeitoa(int n);
int	ft_pointertohexa(unsigned long arg);
int	ft_unsigneditoa(unsigned int n);
#endif