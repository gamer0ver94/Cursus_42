/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:22:11 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/29 21:57:43 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	t_info	*info;

	if (argc < 5)
	{
		printf("This Program Needs 4 Arguments\n");
		printf("Number of Philos\nTime_to_die\nTime_to_eat\nTime_to_sleep\n");
		return (-1);
	}
	else
	{
		table = malloc(sizeof(t_table));
		info = malloc(sizeof(t_info));
		info_init(info, argv);
		create_enviroment(table, info);
		philos_init(table, info);
		simulation(table, info);
	}
	return (0);
}