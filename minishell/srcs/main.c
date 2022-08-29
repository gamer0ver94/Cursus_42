#include "../includes/minishell.h"

int main (int argc, char **argv, char **envp)
{
	if(argc != 1)
		return (1);
	logo();
	get_prompt(envp);
	return (0);
}