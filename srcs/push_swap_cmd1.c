/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:20:42 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 10:38:05 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stk *stk)
{
	if (stk->slit <= stk->size - 2)
	{
		ft_swap_sizet(&stk->stk_fr[stk->slit], &stk->stk_fr[stk->slit + 1]);
		ft_printf("sa\n");
	}
}

void	sb(t_stk *stk)
{
	if (2 <= stk->slit)
	{
		ft_swap_sizet(&stk->stk_fr[stk->slit - 1], &stk->stk_fr[stk->slit - 2]);
		ft_printf("sb\n");
	}
}

// スタックBからAに要素を移す
void	pa(t_stk *stk)
{
	if (1 <= stk->slit)
	{
		stk->slit--;
		ft_printf("pa\n");
	}
}

// スタックAからBに要素を移す
void	pb(t_stk *stk)
{
	if (stk->slit != stk->size)
	{
		stk->slit++;
		ft_printf("pb\n");
	}
}
