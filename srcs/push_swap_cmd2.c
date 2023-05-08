/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:23:02 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/08 09:46:38 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// スタックAをローテート。1番目の要素が最後になる。
void	ra(int *stk, int a0, int size)
{
	int	tmp;

	if (a0 <= size - 2)
	{
		tmp = stk[a0];
		ft_memmove(&stk[a0], &stk[a0 + 1], (size - 1 - a0) * sizeof(int));
		stk[size - 1] = tmp;
	}
}

// スタックBをローテート。一番目の要素が最後になる。
void	rb(int *stk, int a0, int size)
{
	int	tmp;

	if (2 <= a0)
	{
		tmp = stk[0];
		ft_memmove(&stk[0], &stk[1], (a0 - 1) * sizeof(int));
		stk[a0 - 1] = tmp;
	}
}

// スタックAを逆ローテート。最後の要素が最初になる。
void	rra(int *stk, int a0, int size)
{
	int	tmp;

	if (a0 <= size -2)
	{
		tmp = stk[size - 1];
		ft_memmove(&stk[a0 + 1], &stk[a0], (size - 1 - a0) * sizeof(int));
		stk[a0] = tmp;
	}
}

// スタックBをローテート。一番目の要素が最後になる。
void	rrb(int *stk, int a0, int size)
{
	int	tmp;

	if (2 <= a0)
	{
		tmp = stk[a0 - 1];
		ft_memmove(&stk[1], &stk[0], (a0 - 1) * sizeof(int));
		stk[0] = tmp;
	}
}