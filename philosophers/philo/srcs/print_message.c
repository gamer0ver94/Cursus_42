/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:55:46 by dpaulino          #+#    #+#             */
/*   Updated: 2022/10/18 21:31:34 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_message(long time, t_table *philo, char *message)
{
	printf("%ld ms <philo> %d %s\n", time, \
	philo->philosopher->philo_id, message);
}
