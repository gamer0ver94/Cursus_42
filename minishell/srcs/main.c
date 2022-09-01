/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:07:26 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/01 12:16:33 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//testing
void sig_handler(int signal)
{
	if(signal == SIGINT)
	{
		logo("assets/exit_logo.txt");
		printf("\n");
		exit(0);
	}
}

int	main (int argc, char **argv, char **envp)
{
	if (argc != 1)
	{
		printf("no need argv\n");
		return (1);
	}
	
	signal(SIGINT, sig_handler);
	logo("assets/logo.txt");
	get_prompt(envp);
	return (0);
}
