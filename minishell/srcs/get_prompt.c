/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:11 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/30 13:32:14 by dpaulino         ###   ########.fr       */
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

void	struct_init(t_command **prompt)
{
	(*prompt)->cmd = NULL;
	(*prompt)->argc = 0;
	(*prompt)->argv = NULL;
	(*prompt)->next = NULL;
}

void	free_prompt(t_command **prompt)
{
	int	i;

	i = 0;
	if((*prompt)->cmd)
		free((*prompt)->cmd);
	if ((*prompt)->argv)
	{
		while ((*prompt)->argv[i])
		{
			free((*prompt)->argv[i]);
			i++;
		}
	}
	free ((*prompt)->argv);
}

int	get_prompt(char **envp)
{
	t_command	*prompt;
	char		*buffer;
	int i = 0;
	
	prompt = malloc(sizeof(t_command));
	
	while (1)
	{
		struct_init(&prompt);
		buffer = readline(parse_prompt(envp));
		add_history(buffer);
		if(ft_strlen(buffer))
		{
			parse_buffer(buffer, &prompt);
			exec_command(prompt);
			// print_struct(prompt);
		}	
		free_prompt(&prompt);
	}
	return (0);
}
