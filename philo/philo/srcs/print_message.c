/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:55:46 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/26 20:03:14 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_message(long time, t_table *philo, char *message, t_data *data)
{
	pthread_mutex_lock(data->output);
	if (data->is_dead == 0)
	{
		printf("%ld %d %s\n", time, \
		philo->philosopher->philo_id, message);
	}
	pthread_mutex_unlock(data->output);
}
