/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:01:18 by gameoverstation   #+#    #+#             */
/*   Updated: 2022/08/22 16:18:17 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_errors(t_data *data, int error)
{
	if (error == 1)
		ft_putstr_fd("<Error>\nMap have <none> or <more> than 1 Player\n", 2);
	if (error == 2)
		ft_putstr_fd("Error\nThis program need <exactly 1> argument\n", 2);
	if (error == 3)
		ft_putstr_fd("Error\nMap is <not valid>\n", 2);
	if (error == 4)
		ft_putstr_fd("Error\nMap does <not have> closed walls\n", 2);
	if (error == 5)
		ft_putstr_fd("Error\n<Too many> enemys\n", 2);
	if (error == 6)
		ft_putstr_fd("Error\nMap does not have an exit\n", 2);
	if (error == 7)
		ft_putstr_fd("Error\nMap have incompatible caracters\n", 2);
	if (error == 8)
		ft_putstr_fd("Error\nMap have <not> colectable coins\n", 2);
	if (error == 9)
		ft_putstr_fd("Error\n<Impossible> to reach <exit>\n", 2);
	if (error == 10)
		ft_putstr_fd("Error\n<Impossible> to reach <coin>\n", 2);
	if (!data->map.map)
		free(data->map.map);
	exit (1);
}
