/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:22:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 14:42:37 by mogawa           ###   ########.fr       */
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
	return (cnt);
}

void	ft_radix_sort(t_stk *stk)
{
	size_t	i;
	size_t	j;
	size_t	maxbit;
	size_t	bit;

	maxbit = ft_get_max_bits(stk->size, BASE);
	j = 0;
	while (j < maxbit)
	{
		i = 0;
		while (i < stk->size)
		{
			if ((stk->stk_fr[stk->slit] >> j & 1) == 0)
				pb(stk);
			else
				ra(stk);
			i++;
		}
		while (0 < stk->slit)
		{
			pa(stk);
		}
		j++;
	}
}

// void	ft_radix_sort(t_stk *stk)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	maxbit;
// 	size_t	bit;

// 	maxbit = ft_get_max_bits(stk->size, BASE);
// 	j = 0;
// 	while (j < maxbit)
// 	{
// 		i = 0;
// 		while (i < stk->size)
// 		{
// 			bit = ft_get_bit(stk->stkf[stk->slit], j, BASE);
// 			if (bit == 0)
// 			{
// 				pb(stk);
// 				rb(stk);
// 			}
// 			else if (bit == 1)
// 			{
// 				pb(stk);
// 			}
// 			else
// 				ra(stk);
// 			i++;
// 		}
// 		while (0 < stk->slit)
// 		{
// 			if (stk->stkf[stk->slit - 1] == 0)
// 			{
// 				rrb(stk);
// 				pa(stk);
// 			}
// 			else
// 			{
// 				pa(stk);
// 			}
// 		}
// 		j++;
// 	}
// }

static	size_t	ft_get_max(t_stk *stk)
{
	size_t	max;
	size_t	n;

	n = 0;
	max = 0;
	while (stk->slit + n < stk->size)
	{
		if (stk->stk_fr[stk->slit + n] > max)
			max = stk->stk_fr[stk->slit + n];
		n++;
	}
	return (max);
}

static	size_t	ft_get_min(t_stk *stk, size_t *minloc)
{
	size_t	min;
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	min = LONG_MAX;
	while (stk->slit + n < stk->size)
	{
		if (stk->stk_fr[stk->slit + n] < min)
		{
			min = stk->stk_fr[stk->slit + n];
			i++;
		}
		n++;
	}
	*minloc = i;
	return (min);
}

static bool	ft_is_smlsorted(t_stk *stk)
{
	size_t	max;
	size_t	min;
	size_t	dummy;

	max = ft_get_max(stk);
	min = ft_get_min(stk, &dummy);
	dummy = 0;
	if (stk->stk_fr[stk->slit] == min && stk->stk_fr[stk->slit + 2] == max)
		return (true);
	else
		return (false);
}

void	ft_sort_small(t_stk *stk)
{
	size_t	max;
	size_t	i;

	i = 0;
	max = ft_get_max(stk);
	while (1)
	{
		if (ft_is_smlsorted(stk))
			break ;
		if (stk->stk_fr[stk->slit] == max && !ft_is_smlsorted(stk))
		{
			ra(stk);
		}
		if (stk->stk_fr[stk->slit + 1] == max && !ft_is_smlsorted(stk))
		{
			rra(stk);
		}
		if (stk->stk_fr[stk->slit + 2] == max && !ft_is_smlsorted(stk))
		{
			sa(stk);
		}
	}
}

void	ft_sort_ctl(t_stk *stk)
{
	size_t	i;
	size_t	min;
	size_t	minloc;

	if (stk->size == 2)
		sa(stk);
	else if (stk->size < 7)
	{
		i = 0;
		while (stk->size > 3 + i++)
		{
			min = ft_get_min(stk, &minloc);
			while (stk->stk_fr[stk->slit] != min)
			{
				if (minloc > (stk->size - stk->slit) / 2)
					rra(stk);
				else
					ra(stk);
			}
			pb(stk);
		}
		ft_sort_small(stk);
		while (0 < stk->slit)
			pa(stk);
	}
	else
		ft_radix_sort(stk);
}
