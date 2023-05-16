/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:22:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/16 11:18:37 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*/
void	ft_radix_sort(t_stk *stk)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < stk->size)
		{
			if ((stk->stkf[stk->slit] >> j & 1) == 0)
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
