/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:07:00 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/05 13:37:43 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cd_cmd(t_command *prompt, char **envp)
{
	int		i;
	char	*old_pwd;
	char	new_pwd[1000];

	i = 0;
	// old_pwd = ft_strjoin("OLD_PWD=", getenv("PWD"));
	if (!chdir((*prompt).argv[1]))
	{
		while (envp[i])
		{
			//need to add PWD = to path
			if (!ft_strncmp(envp[i], "PWD", 3))
			{
				envp[i] = ft_strjoin("PWD=", getcwd(new_pwd, 1000));
			}
			// if (!ft_strncmp(envp[i], "OLDPWD", 6))
			// {
			// 	envp[i] = old_pwd;
			// }
			i++;
		}
	}
	else
		perror("bash");
	return (0);
}
//need to update oldpwd