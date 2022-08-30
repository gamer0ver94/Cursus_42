/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:15:08 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/31 00:38:46 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (!ft_strncmp(argv[0],"-n", 2))
	{
		printf("\n");
		return (0);
	}
	while (argv[i])
	{
		printf("%s ", argv[i]);
		i++;
	}
	printf("\n");
	return (0);
}
