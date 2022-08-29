/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:51:34 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/29 16:13:19 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_command
{
	char	*cmd;
	int		argc;
	char	**argv;
	char	**flags;
	struct t_command	*next;
}   t_command;
