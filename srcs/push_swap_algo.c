/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:22:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/19 17:29:15 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_get_bit(size_t n, size_t dgt, size_t base)
{
	size_t	bit;
	size_t	i;

	i = 0;
	bit = n;
	while (i < dgt)
	{
		bit /= base;
		i++;
	}
	return (bit % base);
}

static size_t	ft_get_max_bits(size_t n, size_t base)
{
	size_t	cnt;

	cnt = 0;
	while (1)
	{
		cnt++;
		n = n / base;
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
	size_t	n;

	maxbit = ft_get_max_bits(stk->size, BASE);
	j = 0;
	while (j < maxbit)
	{
		i = 0;
		while (i < stk->size)
		{
			n = stk->stkf[stk->slit];
			if (ft_get_bit(n, j, BASE) == 1)
				pb(stk);
			else
				ra(stk);
			i++;
		}
		while (0 < stk->slit)
		{
			rrb(stk);
			pa(stk);
			ra(stk);
		}
		j++;
	}
}
