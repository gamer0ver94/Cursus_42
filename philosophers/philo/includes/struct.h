/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:08:20 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/22 14:18:33 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>

typedef struct s_info
{
	int			n_philos;
	int			time_to_die;
	int			time_to_sleep;
	int			time_to_eat;
	int			n_diner;
	int			eat_time_rules;
	long		starting_time;
}	t_info;

typedef struct s_philosopher
{
	pthread_t			thread_id;
	int					philo_id;
	pthread_mutex_t		fork;
	pthread_mutex_t		eating;
	pthread_mutex_t		all_ate;
	int					n_diner;
	long				last_meal;
	t_info				*info;
}	t_philosopher;

typedef struct s_table
{
	struct s_philosopher	*philosopher;
	struct s_table			*right;
	struct s_table			*left;
}	t_table;

typedef struct s_data
{
	struct s_table			*table;
	struct s_info			*info;
	int						sim_status;
}	t_data;

#endif