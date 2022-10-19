/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:55:50 by keys              #+#    #+#             */
/*   Updated: 2022/10/19 21:08:43 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

static void	get_signal(int sig)
{
	static int	i = 0;
	static char	c;

	if(sig == SIGUSR1)

	if (signal == SIGUSR1)
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
	struct sigaction    s_sa;

	ft_printf("PID: %d\n", getpid());
	sigemptyset(&s_sa.sa_mask);
	s_sa.sa_handler = get_signal;
	s_sa.sa_flags = 0;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	while (1)
		pause();
		//   pause()  は、呼び出したプロセス (またはスレッド) を、 そのプロセスを終了させたり、シグナル
    //    捕捉関数が起動されるような シグナルが配送されるまで、スリープさせる。
	return (0);
}
