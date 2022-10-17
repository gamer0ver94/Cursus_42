/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:22:11 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/17 10:32:15 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5)
	{
		printf("This Program Needs 4 Arguments\n");
		printf("Number of Philos\nTime_to_die\nTime_to_eat\nTime_to_sleep\n");
		return (-1);
	}
	data = malloc(sizeof(t_data));
	data->table = malloc(sizeof(t_table));
	data->info = malloc(sizeof(t_info));
	info_init(data->info, argv);
	create_enviroment(data->table, data->info);
	philos_init(data, data->table, data->info);
	simulation(data);
	return (0);
}