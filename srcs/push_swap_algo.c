/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:22:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/17 15:45:41 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_get_max_bits(size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (1)
	{
		cnt++;
		n = n / 2;
		if (n == 0)
			break ;
	}
	return (cnt + 1);
}

void	ft_radix_sort(t_stk *stk)
{
	size_t	i;
	size_t	j;
	size_t	maxbit;

	maxbit = ft_get_max_bits(stk->size);
	j = 0;
	while (j < maxbit)
	{
		i = 0;
		while (i < stk->size)
		{
			if ((stk->stkf[stk->slit] >> j & 1) == 0)
			{
				pb(stk);
				ft_printf("pb\n");
			}
			else
			{
				ra(stk);
				ft_printf("ra\n");
			}
			i++;
		}
		while (0 < stk->slit)
		{
			pa(stk);
			ft_printf("pa\n");
		}
		j++;
	}
}
