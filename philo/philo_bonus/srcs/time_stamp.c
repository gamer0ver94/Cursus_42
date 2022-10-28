/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:10:36 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/27 12:47:09 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

long	time_update(long starting_time)
{
	int	time;

	time = get_time() - starting_time;
	return (time);
}
