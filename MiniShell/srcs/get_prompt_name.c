/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:56:29 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/24 12:51:09 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_prompt(char *user)
{
	char	*new;
	char	*prompt;
	int		i;
	int		j;
	prompt = strdup("MINISHELL");
	new = malloc(sizeof(char) * strlen(user) - 3);
	i = 0;
	while (user[i + 5])
	{
		new[i] = user[i + 5];
		i++;
	}
	new[i] = '\0';
	prompt = strcat(new, "MINI");
	printf("%s", prompt);
	return (prompt);
}
