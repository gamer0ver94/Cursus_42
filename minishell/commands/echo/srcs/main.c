/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:15:08 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/01 11:51:37 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;

	(void)argc;
	(void)argv;
	(void)envp;
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
	printf("its my echo");
	printf("\n");
	return (0);
}
