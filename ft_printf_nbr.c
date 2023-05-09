/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:11:17 by mogawa            #+#    #+#             */
/*   Updated: 2023/02/01 19:27:18 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// output int 'n'
ssize_t	ft_putnbr_base(unsigned long n, size_t base, char *nbr)
{
	ssize_t	len;

	len = 0;
	if (n >= base)
	{
		len += ft_putnbr_base(n / base, base, nbr);
		len += ft_putnbr_base(n % base, base, nbr);
	}
	else
	{
		len += ft_putchar_cnt(nbr[n % base]);
	}
	return (len);
}

ssize_t	ft_putnbr_int(int n)
{
	ssize_t	len;

	len = 0;
	if (n < 0)
		len += ft_putchar_cnt('-');
	if (n <= -10)
	{
		len += ft_putnbr_int((n / 10) * -1);
		len += ft_putnbr_int((n % 10) * -1);
	}
	else if (n >= 10)
	{
		len += ft_putnbr_int(n / 10);
		len += ft_putnbr_int(n % 10);
	}
	else if (10 > n && n > -10)
	{
		if (n < 0)
			n = n * -1;
		len += ft_putchar_cnt(n + '0');
	}
	return (len);
}
