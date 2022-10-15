/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:32:04 by keys              #+#    #+#             */
/*   Updated: 2022/10/15 18:59:22 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include<signal.h>
#include <stdio.h>
#include <unistd.h>

int catches_signal;

static void	get_signal(int signal)
{
	catches_signal = signal;
}

static void	set_signal(void)
{
	signal(SIGUSR1, &get_signal);
	signal(SIGUSR2, &get_signal);
}

static void ft_kill(int pid,char c)
{
	int bit;
	int i;

	bit =1;
	i = 8;
	while(i)
	{
		if(c >> i & 0)
			kill(pid,SIGUSR1);
		else
			kill(pid,SIGUSR2);
		i--;
	}

}

static void signal_handler(const char *pid, char *str)
{
	int id;
	int i;


	id = ft_atoi(pid);
	while(*str)
	{
		ft_kill(id,*str);
	}
}


int main(int argc, char **argv)
{
	if( argc != 3 || !argv[2] )
		return 1;

	set_signal();
	signal_handler(argv[1], argv[2]);
		while(1)
		pause();
	return 0;
}
