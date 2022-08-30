/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 00:31:50 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/31 00:35:56 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int main (int argc, char **argv, char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        printf("%s\n",envp[i]);
        i++;
    }
    return (0);
}