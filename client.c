/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:32:04 by keys              #+#    #+#             */
/*   Updated: 2022/10/17 11:07:00 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void	ft_kill(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		//システムコールの kill() は、任意のプロセスグループもしくはプロセスにシグナルを送るのに使われる。
		if (c >> i & 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
			//usleep() 関数は (少なくとも) usecマイクロ秒の間、 呼び出し元スレッドの実行を延期する。 
		usleep(100);
	}
}

static void	ft_signal_handler(int pid, char *str)
{

	while (*str)
	{
		ft_kill(pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !argv[2])
		return (1);
	ft_signal_handler(ft_atoi(argv[1]), argv[2]);
	return (0);
}
