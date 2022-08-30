/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:51:34 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/30 13:26:32 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_command
{
	char	*cmd;
	int		argc;
	char	**argv;
	struct t_command	*next;
}   t_command;
