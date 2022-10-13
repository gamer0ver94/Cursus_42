/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:44:19 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/13 10:07:56 by dpaulino         ###   ########.fr       */
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

int		info_init(t_info *info, char**argv);
int		ft_atoi(const char *str);
int		create_enviroment(t_table *table, t_info *info);
int		philos_init(t_table *table, t_info *info);
void	simulation(t_table *table, t_info *info);
void	*start(void *args);
int	threads_init(t_table *table, t_info *info);
int		mutex_init(t_table *table, t_info *info);
int		wait_threads(t_table *table, t_info *info);
int		timestamp_init(t_timestamp *timestamp);
long	time_update(long initial_time);
void eat(pthread_mutex_t *fork1, pthread_mutex_t *fork2, t_table *philo);
#endif