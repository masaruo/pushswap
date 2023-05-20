/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:23:02 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/19 17:22:39 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// スタックAをシフトアップ。1番目の要素が最後になる。
void	ra(t_stk *stk)
{
	size_t	tmp;

	if (stk->slit <= stk->size - 2)
	{
		tmp = stk->stkf[stk->slit];
		ft_memmove(&stk->stkf[stk->slit], &stk->stkf[stk->slit + 1], (stk->size - 1 - stk->slit) * sizeof(size_t));
		stk->stkf[stk->size - 1] = tmp;
		ft_printf("ra\n");
	}
}

// スタックBをシフトアップ。一番目の要素が最後になる。
void	rb(t_stk *stk)
{
	size_t	tmp;

	if (2 <= stk->slit)
	{
		tmp = stk->stkf[stk->slit - 1];
		ft_memmove(&stk->stkf[1], &stk->stkf[0], (stk->slit - 1) * sizeof(size_t));
		stk->stkf[0] = tmp;
		ft_printf("rb\n");
	}
}

// スタックBをシフトダウン。最後の要素が最初になる。
void	rrb(t_stk *stk)
{
	size_t	tmp;

	if (2 <= stk->slit)
	{
		tmp = stk->stkf[0];
		ft_memmove(&stk->stkf[0], &stk->stkf[1], (stk->slit - 1) * sizeof(size_t));
		stk->stkf[stk->slit - 1] = tmp;
		ft_printf("rrb\n");
	}
}

// スタックAをシフトダウン。最後の要素が最初になる。
void	rra(t_stk *stk)
{
	size_t	tmp;

	if (stk->slit <= stk->size - 2)
	{
		tmp = stk->stkf[stk->size - 1];
		ft_memmove(&stk->stkf[stk->slit + 1], &stk->stkf[stk->slit], (stk->size - 1 - stk->slit) * sizeof(size_t));
		stk->stkf[stk->slit] = tmp;
		ft_printf("rra\n");
	}
}
