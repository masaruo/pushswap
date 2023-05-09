/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:34:44 by mogawa            #+#    #+#             */
/*   Updated: 2023/02/01 19:27:37 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
ssize_t	ft_arg_handler(char c, va_list *ap);
ssize_t	ft_putchar_cnt(char c);
ssize_t	ft_putstr_cnt(char *s);
ssize_t	ft_putnbr_base(unsigned long n, size_t base, char *nbr);
ssize_t	ft_putnbr_int(int n);

#endif