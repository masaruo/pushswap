/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:41:06 by mogawa            #+#    #+#             */
/*   Updated: 2023/02/01 20:18:58 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		n;
	ssize_t	len;

	n = 0;
	len = 0;
	va_start(ap, fmt);
	while (fmt[n])
	{
		if (fmt[n] == '%')
		{
			n++;
			len += ft_arg_handler(fmt[n], &ap);
		}
		else
			len += ft_putchar_cnt(fmt[n]);
		n++;
	}
	va_end(ap);
	return ((int)len);
}
