/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:23:02 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/07 23:01:08 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// スタックAをローテート。1番目の要素が最後になる。
void	ra(int *stk, int a0, int size)
{
	int	tmp;

	tmp = stk[a0];
	ft_memmove(&stk[a0], &stk[a0 + 1], (size - 1 - a0) * sizeof(int));
	stk[size - 1] = tmp;
}

// スタックBをローテート。一番目の要素が最後になる。
void	rb(int *stk, int a0, int size)
{
	int	tmp;

	tmp = stk[0];
	ft_memmove(&stk[0], &stk[1], (a0 - 1) * sizeof(int));
	stk[a0 - 1] = tmp;
}

// スタックAをローテート。1番目の要素が最後になる。
void	rra(int *stk, int a0, int size)
{
	int	tmp;

	tmp = stk[a0];
	ft_memmove(&stk[a0], &stk[a0 + 1], (size - 1 - a0) * sizeof(int));
	stk[size - 1] = tmp;
}

// スタックBをローテート。一番目の要素が最後になる。
void	rrb(int *stk, int a0, int size)
{
	int	tmp;

	tmp = stk[0];
	ft_memmove(&stk[0], &stk[1], (a0 - 1) * sizeof(int));
	stk[a0 - 1] = tmp;
}