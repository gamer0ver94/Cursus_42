/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:11:17 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/17 15:07:23 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_char(unsigned char c, int pid)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (c >> bit & 1)
		{
			if (kill(pid, SIGUSR1))
			{
				ft_putstr_fd("Signal not received\n", 1);
				exit (1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2))
			{
				ft_putstr_fd("Signal not received\n", 1);
				exit (1);
			}
		}
		pause();
		usleep(200);
	}
}

void	send_message(char *msg, int pid)
{
	while (*msg)
	{
		send_char((unsigned char)*msg, pid);
		msg++;
	}
	send_char('\0', pid);
	send_char('\n', pid);
	ft_putstr_fd("Message Received\n", 1);
}

void	sended(int signal)
{
	(void)signal;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error\nNeed the right number of arguments\n", 2);
		return (1);
	}
	signal(SIGUSR1, sended);
	send_message(argv[2], ft_atoi(argv[1]));
	return (0);
}
