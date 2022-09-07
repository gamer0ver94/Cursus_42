/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:11 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/07 11:01:06 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//printout the logo
char	*parse_prompt(void)
{
	char	*parser;
	char	*tmp;
	char	current_dir[1024];
	
	parser = ft_strdup(BLACK_CLR);
	tmp = ft_strdup(parser);
	free(parser);
	parser = ft_strjoin(tmp, getenv("USER"));
	free(tmp);
	tmp = ft_strjoin(parser, BOLD);
	free(parser);
	parser = ft_strjoin(tmp, GREEN_CLR);
	free(tmp);
	tmp = ft_strjoin(parser, "@MINISHELL:");
	free(parser);
	parser = ft_strjoin(tmp, MAGENTA_CLR);
	free(tmp);
	tmp = ft_strjoin(parser, "~");
	free(parser);
	parser = ft_strjoin(tmp, getcwd(current_dir, 1024));
	free(tmp);
	tmp = ft_strjoin(parser, WHITE_CLR);
	free(parser);
	parser = ft_strjoin(tmp, "$ ");
	free(tmp);
	return (parser);
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
	char		*ptr;

	prompt = malloc(sizeof(t_command));
	while (1)
	{
		ptr = parse_prompt();
		struct_init(&prompt);
		buffer = readline(ptr);
		add_history(buffer);
		if (ft_strlen(buffer))
		{
			if (!parse_buffer(buffer, &prompt))
			{
				print_struct(prompt);
				exec_command(prompt, envp);
			}
		}
		free(buffer);
		free(ptr);
		free_prompt(&prompt);
	}
	return (0);
}
