/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:07:00 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/03 00:04:58 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int cd_cmd(t_command *prompt, char **envp)
{
    int i;
    char *old_pwd;
    i = 0;
    if(!chdir((*prompt).argv[1]))
    {
        while (envp[i])
        {
            //need to add PWD = to path
            if (!strncmp(envp[i], "PWD", 3))
            {
                old_pwd = envp[i];
                envp[i] = prompt->argv[1];
            }
            if (!strncmp(envp[i], "OLD_PWD", 7))
            {
                envp[i] = old_pwd;
            }
            i++;
        }
        
    }
    else
        perror("bash");
    return (0);
}