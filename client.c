/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:32:04 by keys              #+#    #+#             */
/*   Updated: 2022/10/26 22:44:03 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_kill(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
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
	if (kill(ft_atoi(argv[1]), 0) == -1)
		return (1);
	ft_signal_handler(ft_atoi(argv[1]), argv[2]);
	return (0);
}
