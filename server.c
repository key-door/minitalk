/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:55:50 by keys              #+#    #+#             */
/*   Updated: 2022/10/17 08:45:44 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int			catch_signal;

static void	get_signal(int signal)
{
	static int	i;
	static int	c;

	i++;
	if (signal == SIGUSR1)
		c = (c << 1) + 1;
	else
		c = (c << 1) + 0;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

static void	set_signal(void)
{
	signal(SIGUSR1, &get_signal);
	signal(SIGUSR2, &get_signal);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	set_signal();
	while (1)
		pause();
	return (0);
}
