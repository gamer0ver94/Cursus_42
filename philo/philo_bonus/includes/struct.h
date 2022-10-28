/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:08:20 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/27 14:15:09 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <semaphore.h>

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
	pid_t				process_id;
	int					philo_id;
	int					n_diner;
	long				last_meal;
	int					is_eating;
	long				death_time;
	long				finish_eat_time;
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
	sem_t					*output;
	sem_t					*fork;
	sem_t					*s_status;
	int						is_dead;
}	t_data;

#endif