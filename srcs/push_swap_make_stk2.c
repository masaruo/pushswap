/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_make_stk2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:51:13 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 16:34:26 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prefix_cnt(const char *s, int *is_minus, int *j)
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

int	ft_isspace_cnt(const char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}
