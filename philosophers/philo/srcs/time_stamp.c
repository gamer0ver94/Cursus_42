/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:10:36 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/13 09:58:59 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	timestamp_init(t_timestamp *timestamp)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	timestamp->initial_time = current_time.tv_sec;
	timestamp->time = 0;
	return (0);
}

long	time_update(long initial_time)
{
	struct timeval	current_time;
			
	gettimeofday(&current_time, NULL);
	initial_time = (current_time.tv_sec - initial_time) * 1000;
	return (initial_time);
}