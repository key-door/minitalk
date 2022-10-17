/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:55:50 by keys              #+#    #+#             */
/*   Updated: 2022/10/17 11:01:46 by kyoda            ###   ########.fr       */
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
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, &get_signal);
	signal(SIGUSR2, &get_signal);
	while (1)
		pause();
		//   pause()  は、呼び出したプロセス (またはスレッド) を、 そのプロセスを終了させたり、シグナル
    //    捕捉関数が起動されるような シグナルが配送されるまで、スリープさせる。
	return (0);
}
