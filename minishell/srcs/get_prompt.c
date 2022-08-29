/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:11 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/29 17:15:58 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//printout the logo
char	*parse_prompt(char **envp)
{
	char	*parser;

	parser = ft_strdup(BLACK_CLR);
	parser = ft_strjoin(parser, getenv("USER"));
	parser = ft_strjoin(parser, BOLD);
	parser = ft_strjoin(parser, GREEN_CLR);
	parser = ft_strjoin(parser, "@MINISHELL:");
	parser = ft_strjoin(parser, MAGENTA_CLR);
	parser = ft_strjoin(parser, "~");
	parser = ft_strjoin(parser, getenv("PWD"));
	parser = ft_strjoin(parser, WHITE_CLR);
	parser = ft_strjoin(parser, "$ ");
	return (parser);
	//memory leak
}

int	get_prompt(char **envp)
{
	t_command	*prompt;
	char		*buffer;
	int i = 0;
	prompt = malloc(sizeof(t_command));
	while (1)
	{
		buffer = readline(parse_prompt(envp));
		add_history(buffer);
		// if(buffer[0] == '\n')
		// {
			parse_buffer(buffer, &prompt);
			while(prompt->argv[i])
			{
				printf("%s", prompt->argv[i]);
				i++;
			}
		// }
		
	}
	return (0);
}
