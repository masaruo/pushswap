/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:20:42 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/17 14:42:51 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_sizet(size_t *a, size_t *b)
{
	size_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stk *stk)
{
	if (stk->slit <= stk->size - 2)
	{
		ft_swap_sizet(&stk->stkf[stk->slit], &stk->stkf[stk->slit + 1]);
	}
}

void	sb(t_stk *stk)
{
	if (2 <= stk->slit)
	{
		ft_swap_sizet(&stk->stkf[stk->slit - 1], &stk->stkf[stk->slit - 2]);
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
