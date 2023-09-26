/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:55:50 by keys              #+#    #+#             */
/*   Updated: 2022/10/26 23:06:31 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// struct sigaction {
//     void     (*sa_handler)(int);
//     void     (*sa_sigaction)(int, siginfo_t *, void *);
//     sigset_t   sa_mask;
//     int        sa_flags;
//     void     (*sa_restorer)(void); };

static void	get_signal(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIGUSR2)
		c = c << 1;
	else
		c = (c << 1) + 1;
	if (++i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sa;
	pid_t				pid;

	pid = getpid();
	if (pid < 0)
		return (1);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sigemptyset(&s_sa.sa_mask);
	s_sa.sa_handler = get_signal;
	s_sa.sa_flags = 0;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	while (1)
		pause();
	return (0);
}
