/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:08:20 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/13 10:00:07 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_timestamp
{
	long			time;	
}	t_timestamp;

typedef struct s_philosopher
{
	pthread_t			thread_id;
	int					philo_id;
	pthread_mutex_t		fork;
	struct s_timestamp	*time;
	int					n_diner;
	int					last_meal;
}	t_philosopher;

typedef struct s_table
{
	struct s_philosopher	*philosopher;
	struct s_timestamp		*timestamp;
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