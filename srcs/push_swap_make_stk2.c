/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_make_stk2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:51:13 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 20:29:43 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_prefix_cnt(const char *s, int *is_minus, int *j)
{
	*is_minus = 0;
	while (ft_isspace_cnt(s[*j]))
		*j = *j + 1;
	if (s[*j] == '-')
		*is_minus = -1;
	if (s[*j] == '-' || s[*j] == '+')
		*j = *j + 1;
	if (!ft_isdigit(s[*j]))
		ft_err_exit();
	return ;
}

static int	ft_isspace_cnt(const char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi_cnt(const char *str)
{
	int			is_minus;
	int			num;
	const char	*s;

	ft_prefix_cnt(str, &is_minus);
	num = 0;
	s = str;
	while (s[*j])
	{	
		if (!ft_isdigit(s[*j]))
			ft_err_exit();
		if (num > INT_MAX / 10)
			ft_err_exit();
		num = num * 10;
		if (!is_minus && num > INT_MAX - (s[*j] - '0'))
			ft_err_exit();
		if (is_minus && num - 1 > INT_MAX - (s[*j] - '0'))
			ft_err_exit();
		num = num + (s[*j] - '0');
		*j = *j + 1;
	}
	if (is_minus)
		return ((int)(num * -1));
	else
		return ((int)num);
}
