/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:55:50 by keys              #+#    #+#             */
/*   Updated: 2022/10/15 18:41:27 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<sys/types.h>
#include "libft/libft.h"
#include<signal.h>
#include <stdio.h>

int catch_signal;

static void	get_signal(int signal)
{
	catch_signal = signal;
}

static void	set_signal(void)
{
	signal(SIGUSR1, &get_signal);
	signal(SIGUSR2, &get_signal);
}

int main(void)
{
	pid_t pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	set_signal();
	while(1)
		pause();
	return 0;
}
