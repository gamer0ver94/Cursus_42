/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:40:59 by dpaulino          #+#    #+#             */
/*   Updated: 2022/08/17 15:13:00 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	receive_sig(int signal, siginfo_t *info, void *ctx)
{
	static unsigned char	c;
	static int				bit;

	(void)ctx;
	bit++;
	if (signal == SIGUSR1)
		c = c | 1;
	if (bit < 8)
			c <<= 1;
	if (bit == 8)
	{
		write (1, &c, 1);
		bit = 0;
		c = 0;
	}
	usleep(200);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig_action;
	int					pid;

	pid = getpid();
	sig_action.sa_flags = SA_SIGINFO;
	sig_action.sa_sigaction = receive_sig;
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	ft_putstr_fd("THE PID from server is :\n", 2);
	ft_putstr_fd(ft_itoa(pid), 2);
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
