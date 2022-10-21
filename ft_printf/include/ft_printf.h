/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:13:28 by kyoda             #+#    #+#             */
/*   Updated: 2022/10/11 12:15:09 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_putchr(int c);
int	ft_puthex(unsigned int n, char c);
int	ft_putnbr(int n);
int	ft_put_ptr(uintptr_t ptr);
int	ft_putstr(char *p);
int	ft_putnbr_ui(unsigned int n);

#endif
