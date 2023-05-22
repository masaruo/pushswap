/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_make_stk2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:51:13 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 23:54:59 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static size_t	ft_prefix(const char *s, int *is_minus)
{
	size_t	j;

	j = 0;
	*is_minus = 0;
	while (ft_isspace(s[j]))
		j++;
	if (s[j] == '-')
		*is_minus = -1;
	if (s[j] == '-' || s[j] == '+')
		j++;
	if (!ft_isdigit(s[j]))
		ft_err_exit();
	return (j);
}

int	ft_xatoi(const char *s)
{
	int			is_minus;
	int			num;
	size_t		j;

	j = ft_prefix(s, &is_minus);
	num = 0;
	while (s[j])
	{	
		if (!ft_isdigit(s[j]))
			ft_err_exit();
		if (num > INT_MAX / 10)
			ft_err_exit();
		num = num * 10;
		if (!is_minus && num > INT_MAX - (s[j] - '0'))
			ft_err_exit();
		if (is_minus && num - 1 > INT_MAX - (s[j] - '0'))
			ft_err_exit();
		num = num + (s[j] - '0');
		j++;
	}
	if (is_minus)
		return ((int)(num * -1));
	else
		return ((int)num);
}
