/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:22:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/16 15:41:40 by mogawa           ###   ########.fr       */
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
