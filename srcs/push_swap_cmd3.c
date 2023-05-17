/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:01:40 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/17 16:14:42 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stk *stk)
{
	sa(stk);
	sb(stk);
}

void	rr(t_stk *stk)
{
	ra(stk);
	rb(stk);
}

void	rrr(t_stk *stk)
{
	rra(stk);
	rrb(stk);
}

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
