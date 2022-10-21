/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:41:51 by kyoda             #+#    #+#             */
/*   Updated: 2022/10/11 12:51:45 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put(unsigned int n, int len, char c)
{
	char	ans;

	if (n >= 16)
	{
		len = put(n / 16, len, c);
		len = put(n % 16, len, c);
	}
	else
	{
		if (n <= 9)
		{
			ans = n + '0';
			len += write(1, &ans, 1);
		}
		else
		{
			ans = n + c;
			len += write(1, &ans, 1);
		}
	}
	return (len);
}

int	ft_puthex(unsigned int n, char c)
{
	int	len;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	len += put(n, 0, c);
	return (len);
}
