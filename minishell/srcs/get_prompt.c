/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:11 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/28 01:40:34 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//printout the logo
char    *parse_prompt(char **envp)
{
	char    *parser;
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

int parse_buffer(char *buffer, t_command **prompt)
{
	if (!ft_strncmp(buffer, "echo",4))
		(*prompt)->cmd = "echo";
	return (0);
}

int get_prompt (char **envp)
{
	t_command   *prompt;
	char    *buffer;
	
	prompt = malloc(sizeof(t_command));
	while (1)
	{
		buffer = readline(parse_prompt(envp));
		add_history(buffer);
		parse_buffer(buffer, &prompt);
		if(!ft_strncmp(buffer, "exit",4))
		{
			printf("<%s>\n",prompt->cmd);
			free(buffer);
			free(prompt);
			exit(0);
		}
		if(!ft_strncmp(prompt->cmd, "echo",4))
			printf("u wrote echo right?\n");
	}
}