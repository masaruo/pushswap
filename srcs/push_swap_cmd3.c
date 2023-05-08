/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:01:40 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/08 11:52:23 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(int *stk, int a0, int size)
{
	sa(stk, a0, size);
	sb(stk, a0, size);
}

void	rr(int *stk, int a0, int size)
{
	ra(stk, a0, size);
	rb(stk, a0, size);
}

void	rrr(int *stk, int a0, int size)
{
	rra(stk, a0, size);
	rrb(stk, a0, size);
}
