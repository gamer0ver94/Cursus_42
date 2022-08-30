#include "../includes/minishell.h"
void	*buildin_path(char *cmd)
{
	char *str;
	char *tmp;
	tmp = ft_strdup("builtin/");
	str = ft_strjoin(tmp,cmd);
	free(tmp);
	return (str);
}
void    exec_command(t_command *prompt)
{
	char *path;
	pid_t pid;

	path = buildin_path(prompt->cmd);
	pid = fork();
	if(pid == 0)
		if(execv(path, prompt->argv) == -1)
			printf("%s: command not found\n",prompt->cmd);
	wait (&pid);
	free(path);
}