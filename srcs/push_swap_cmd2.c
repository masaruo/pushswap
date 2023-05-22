/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:23:02 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 16:47:09 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// スタックAをシフトアップ。1番目の要素が最後になる。
void	ra(t_stk *stk)
{
	size_t	tmp;

	if (stk->slit <= stk->size - 2)
	{
		tmp = stk->stk_fr[stk->slit];
		ft_memmove(&stk->stk_fr[stk->slit], &stk->stk_fr[stk->slit + 1], \
			(stk->size - 1 - stk->slit) * sizeof(size_t));
		stk->stk_fr[stk->size - 1] = tmp;
		ft_printf("ra\n");
	}
}

// スタックBをシフトアップ。一番目の要素が最後になる。
void	rb(t_stk *stk)
{
	size_t	tmp;

	if (2 <= stk->slit)
	{
		tmp = stk->stk_fr[stk->slit - 1];
		ft_memmove(&stk->stk_fr[1], &stk->stk_fr[0], \
			(stk->slit - 1) * sizeof(size_t));
		stk->stk_fr[0] = tmp;
		ft_printf("rb\n");
	}
}

// スタックBをシフトダウン。最後の要素が最初になる。
void	rrb(t_stk *stk)
{
	size_t	tmp;

	if (2 <= stk->slit)
	{
		tmp = stk->stk_fr[0];
		ft_memmove(&stk->stk_fr[0], &stk->stk_fr[1], \
			(stk->slit - 1) * sizeof(size_t));
		stk->stk_fr[stk->slit - 1] = tmp;
		ft_printf("rrb\n");
	}
}

// スタックAをシフトダウン。最後の要素が最初になる。
void	rra(t_stk *stk)
{
	size_t	tmp;

	if (stk->slit <= stk->size - 2)
	{
		tmp = stk->stk_fr[stk->size - 1];
		ft_memmove(&stk->stk_fr[stk->slit + 1], &stk->stk_fr[stk->slit], \
			(stk->size - 1 - stk->slit) * sizeof(size_t));
		stk->stk_fr[stk->slit] = tmp;
		ft_printf("rra\n");
	}
}
