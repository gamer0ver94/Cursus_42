/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:25:13 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/29 13:45:53 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
#include "../libft/libft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "structs.h"
#include <signal.h>
//STRING COLORS
#define BLACK_CLR "\e[39m"
#define RED_CLR "\e[41m"
#define GREEN_CLR "\e[32m"
#define YELLOW_CLR "\e[33m"
#define BLUE_CLR "\e[34m"
#define MAGENTA_CLR "\e[35m"
#define CYAN_CLR "\e[36m"
#define LIGHT_GRAY_CLR "\e[37m"
#define WHITE_CLR "\e[97m"
#define NORMAL_CLR "\e[21m"
#define BOLD "\e[1m"
#define RESET_ATT "\e[0m"
int get_prompt(char **envp);
int logo(void);
int	parse_buffer(char *buffer, t_command **prompt);
#endif