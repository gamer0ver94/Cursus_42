/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:04:17 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/22 14:20:47 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	info_init(t_info *info, char**argv)
{
	info->n_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		info->n_diner = ft_atoi(argv[5]);
		info->eat_time_rules = TRUE;
	}
	else
	{
		info->n_diner = 0;
		info->eat_time_rules = FALSE;
	}
	return (0);
}
