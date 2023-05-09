/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:05:27 by mogawa            #+#    #+#             */
/*   Updated: 2023/02/01 20:18:48 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// outputs the string 's' to the file 'fd'
ssize_t	ft_putstr_cnt(char *s)
{
	char	*str;
	ssize_t	n;

	n = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	str = s;
	while (*str)
	{
		n += ft_putchar_cnt(*str);
		str++;
	}
	return (n);
}

ssize_t	ft_putchar_cnt(char c)
{
	ssize_t	n;

	n = write(1, &c, 1);
	return (n);
}

// remember to pass va_list ap as a pointer so that va_arg can move forward
ssize_t	ft_arg_handler(char c, va_list *ap)
{
	ssize_t	n;

	n = 0;
	if (c == '%')
		n = ft_putchar_cnt('%');
	else if (c == 'c')
		n = ft_putchar_cnt(va_arg(*ap, int));
	else if (c == 's')
		n = ft_putstr_cnt(va_arg(*ap, char *));
	else if (c == 'p')
	{
		n = ft_putstr_cnt("0x");
		n += ft_putnbr_base(va_arg(*ap, unsigned long), 16, "0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		n = ft_putnbr_int(va_arg(*ap, int));
	else if (c == 'u')
		n = ft_putnbr_base(va_arg(*ap, unsigned int), 10, "0123456789");
	else if (c == 'x')
		n = ft_putnbr_base(va_arg(*ap, unsigned int), 16, "0123456789abcdef");
	else if (c == 'X')
		n = ft_putnbr_base(va_arg(*ap, unsigned int), 16, "0123456789ABCDEF");
	return (n);
}

/* https://stackoverflow.com/questions/3369588/
pass-va-list-or-pointer-to-va-list
*/