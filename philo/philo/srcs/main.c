/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:22:11 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/31 14:59:15 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_invalid_args(int argc, char **argv)
{
	if (argc < 5)
	{
		write(2, "This Program Needs 4 Arguments\n", 31);
		write(2, "Number of Philos\nTime_to_die\nTime_to_eat\nTime_to_sleep\n", 55);
		return (-1);
	}
	else if (atoi(argv[1]) < 1 || atoi(argv[2]) < 1 || atoi(argv[3]) < 1 \
	|| atoi(argv[4]) < 1)
	{
		printf("Invalid arguments\n");
		return (-1);
	}
	else if (argv[5] && atoi(argv[5]) < 1)
	{
		printf("Invalid arguments\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_invalid_args(argc, argv) == -1)
		return (-1);
	data = malloc(sizeof(t_data));
	data->table = malloc(sizeof(t_table));
	data->info = malloc(sizeof(t_info));
	info_init(data->info, argv);
	create_enviroment(data->table, data->info);
	philos_init(data, data->table, data->info);
	simulation(data);
	free_data(data);
	return (0);
}
