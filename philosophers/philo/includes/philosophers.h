/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:44:19 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/17 13:06:49 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include "struct.h"
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# define TRUE 1
# define FALSE 0

int			info_init(t_info *data, char**argv);
int			ft_atoi(const char *str);
int			create_enviroment(t_table *table, t_info *info);
int			philos_init(t_data *data, t_table *table, t_info *info);
void		simulation(t_data *data);
void		*start(void *args);
int			threads_init(t_data *data);
int			mutex_init(t_table *table, t_info *info);
int	wait_threads(t_data *data);
long	get_time(void);
long	time_update(long starting_time);
void eating_time(pthread_mutex_t *fork1, pthread_mutex_t *fork2, t_table *philo, long time);
void    sleeping_time(t_table *philo, long time);
void    thinking_time(t_table *philo, long time);
#endif