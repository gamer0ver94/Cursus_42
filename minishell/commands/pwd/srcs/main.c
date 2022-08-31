/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 00:27:32 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/31 15:52:53 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
    (void)argc;
	(void)argv;
	(void)envp;
    printf("%s",getenv("PWD\n"));
    return (0);
}