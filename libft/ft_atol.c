/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu2204 <ubuntu2204@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:04:00 by keys              #+#    #+#             */
/*   Updated: 2023/07/29 21:46:55 by ubuntu2204       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_is_over(unsigned long long result, unsigned long long cutoff,
		unsigned long long last, const char *str)
{
	if (result == cutoff)
	{
		if ((((unsigned long long)(*str - '0')) <= last) && (str[1]
				&& (ft_isdigit(str[1]) != 0)))
			return (true);
	}
	if (result < cutoff)
		return (true);
	return (false);
}

static long long	ft_overlong(const char *str,
								unsigned long long result,
								int base,
								long long flag)
{
	unsigned long long	cutoff;
	unsigned long long	last;

	cutoff = (unsigned long long)LONG_MAX / (unsigned long long)base;
	last = (unsigned long long)LONG_MAX % (unsigned long long)base;
	if (result > cutoff)
		return (flag);
	else if (result <= cutoff)
	{
		if (ft_is_over(result, cutoff, last, str))
		{
			result *= (unsigned long long)base;
			result += (unsigned long long)(*str - '0');
			str++;
		}
		else
			return (flag);
	}
	if (flag == (long long)LONG_MIN)
		return ((long long)result * -1LL);
	return ((long long)result);
}

static long long	ft_strtol(const char *str, int base, long long flag)
{
	unsigned long long	result;

	result = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (result >= ((unsigned long long)LONG_MAX
					/ (unsigned long long)base))
				return (ft_overlong(str, result, base, flag));
			result *= (unsigned long long)base;
			result += (unsigned long long)(*str - '0');
			str++;
		}
		else
			break ;
	}
	if (flag == (long long)LONG_MIN)
	{
		return ((long long)result * -1LL);
	}
	return ((long long)result);
}

long	ft_atol(const char *nptr)
{
	long long	ans;
	long long	flag;
	int			i;

	i = 0;
	flag = LONG_MAX;
	while (ft_isspace((int)nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		flag = LONG_MIN;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	ans = ft_strtol(&nptr[i], 10, flag);
	return ((long)ans);
}
