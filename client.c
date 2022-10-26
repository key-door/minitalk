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

#include "libft/libft.h"
//sigusr1 sigusr2
//http://uralowl.my.coocan.jp/unix/job/UNIX/kernel/signal.html

static void	ft_kill(int pid, char c)
{
	int	i;

	i = 8;
	//ビット文字列データ
	//https://www.microfocus.co.jp/manuals/ED60/VS2019/BKPFPFDATABITSTRING.html
	// 1 => 0000 0001     6 => 0000 0110
	while (i--)
	{
		// >> 右シフト　<<　左シフト
		// & AND。両方１のときに１、それ以外は0にする演算子
		// 1001 1100
		//
		// 0000 0001
		// 0000 0001
		if (c >> i & 1)
			kill(pid, SIGUSR1);

		else
			kill(pid, SIGUSR2);
		//マイクロ秒単位で実行を延期する
		//https://linuxjm.osdn.jp/html/LDP_man-pages/man3/usleep.3.html
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
	//kill - プロセスに対して，シグナルを送る．
	//https://linuxjm.osdn.jp/html/LDP_man-pages/man2/kill.2.html
	//sig が 0 の場合、kill() はエラー検査を行います.
	//sig = 0 の場合シグナルは送信されない．pid 引数が正しいかどうかチェックする
	if (kill(ft_atoi(argv[1]), 0) == -1)
		return (1);
	ft_signal_handler(ft_atoi(argv[1]), argv[2]);
	return (0);
}
