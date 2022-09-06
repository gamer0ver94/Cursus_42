/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:07:26 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/06 19:10:05 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//testing
// void	sig_handler(int signal)
// {
// 	if (signal == SIGINT)
// 	{
// 		logo("assets/exit_logo.txt");
// 		printf("\n");
// 		exit(0);
// 	}
// }

// void	get_oldpwd(char **envp)
// {
// 	int		i;
// 	char	tmp[1000];

// 	i = 0;
// 	while (ft_strncmp(envp[i], "OLDPWD", 6))
// 	{
// 		i++;
// 	}
// 	envp[i] = ft_strjoin("OLDPWD=", getcwd(tmp, 1000));
// }

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1)
	{
		printf("no need argv\n");
		return (1);
	}
	// get_oldpwd(envp);
	logo("assets/logo.txt");
	get_prompt(envp);
	return (0);
}
