/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:20:42 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/15 19:24:57 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(size_t *a, size_t *b)
{
	size_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stk *stk)
{
	if (stk->slit <= stk->size - 2)
	{
		ft_swap(&stk->stkf[stk->slit], &stk->stkf[stk->slit + 1]);
	}
}

void	sb(t_stk *stk)
{
	if (2 <= stk->size)
	{
		ft_swap(&stk->stkf[stk->size - 1], &stk->stkf[stk->size - 2]);
	}
}

// スタックBからAに要素を移す
void	pa(t_stk *stk)
{
	if (1 <= stk->slit)
	{
		stk->slit--;
	}
}

// スタックAからBに要素を移す
void	pb(t_stk *stk)
{
	if (stk->slit != stk->size)
	{
		stk->slit++;
	}
}

// void	pa(int *stk, int *a0, int size)
// {
// 	if (1 <= *a0)
// 	{
// 		*a0 = *a0 - 1;
// 	}
// }

// void	pb(int *stk, int *a0, int size)
// {
// 	if (*a0 != size)
// 	{
// 		*a0 = *a0 + 1;
// 	}
// }
