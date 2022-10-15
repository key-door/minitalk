/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:32:04 by keys              #+#    #+#             */
/*   Updated: 2022/10/15 14:37:57 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<signal.h>
#include <stdio.h>
#include <unistd.h>

void ()
{

}
int main(int argc, char **argv)
{
	if( argc != 3 || !argv[2] )
		return 1;

	signal(SIGUSR1, signal_handler);
	return 0;
}
