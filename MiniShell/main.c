/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:26:15 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/24 12:33:38 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;

	prompt = get_prompt(envp[1]);
	// printf("%s",envp[2]);
	// while (1)
	// {
	// 	readline(prompt);
	// }
	return (0);
}
