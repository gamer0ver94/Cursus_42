/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:08:20 by dpaulino          #+#    #+#             */
/*   Updated: 2022/09/29 14:28:39 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_philosopher
{
	pthread_t		thread_id;
	int				philo_id;
	pthread_mutex_t	fork;
	int				n_diner;
}	t_philosopher;

typedef struct s_table
{
	struct s_philosopher	*philosopher;
	struct s_table			*right;
	struct s_table			*left;
}	t_table;

typedef struct s_info
{
	int	n_philos;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
}	t_info;

#endif