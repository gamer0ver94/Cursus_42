/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:51:34 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/27 18:59:10 by dpaulino         ###   ########.fr       */
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
