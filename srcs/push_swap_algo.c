/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:22:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/15 21:19:32 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_stk *stk)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < 32)
	{
		while (i < stk->size)
		{
			if ((stk[i] >> j & 1) == 0)
				// pb(stk, a0ptr, size);
			i++;
		}
	}
}
