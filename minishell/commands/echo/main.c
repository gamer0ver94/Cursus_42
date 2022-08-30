/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:15:08 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/30 16:26:23 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		printf("%s", argv[i]);
		i++;
	}
	printf("\n");
	return (0);
}
