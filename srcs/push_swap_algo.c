/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:22:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 23:11:17 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_get_minmax(t_stk *stk, size_t *max, size_t *min)
{
	size_t	n;
	size_t	minloc;

	n = 0;
	minloc = 0;
	*min = LONG_MAX;
	*max = 0;
	while (stk->slit + n < stk->size)
	{
		if (stk->stk_fr[stk->slit + n] < *min)
		{
			*min = stk->stk_fr[stk->slit + n];
			minloc++;
		}
		if (stk->stk_fr[stk->slit + n] > *max)
			*max = stk->stk_fr[stk->slit + n];
		n++;
	}
	return (minloc);
}

static bool	ft_is_smlsorted(t_stk *stk)
{
	size_t	max;
	size_t	min;

	ft_get_minmax(stk, &max, &min);
	if (stk->stk_fr[stk->slit] == min && stk->stk_fr[stk->slit + 2] == max)
		return (true);
	else
		return (false);
}

void	ft_sort_triple(t_stk *stk)
{
	size_t	max;
	size_t	min;

	ft_get_minmax(stk, &max, &min);
	while (1)
	{
		if (ft_is_smlsorted(stk))
			break ;
		if (stk->stk_fr[stk->slit] == max && !ft_is_smlsorted(stk))
			ra(stk);
		if (stk->stk_fr[stk->slit + 1] == max && !ft_is_smlsorted(stk))
			rra(stk);
		if (stk->stk_fr[stk->slit + 2] == max && !ft_is_smlsorted(stk))
			sa(stk);
	}
}

void	ft_sort_sml(t_stk *stk)
{
	size_t	i;
	size_t	max;
	size_t	min;
	size_t	minloc;

	i = 0;
	while (stk->size > 3 + i)
	{
		minloc = ft_get_minmax(stk, &max, &min);
		while (stk->stk_fr[stk->slit] != min)
		{
			if (minloc > (stk->size - stk->slit) / 2)
				rra(stk);
			else
				ra(stk);
		}
		pb(stk);
		i++;
	}
	ft_sort_triple(stk);
	while (0 < stk->slit)
		pa(stk);
}

void	ft_sort_ctl(t_stk *stk)
{
	if (stk->size == 2)
		sa(stk);
	else if (stk->size < 7)
		ft_sort_sml(stk);
	else
		ft_radix_sort(stk);
}
