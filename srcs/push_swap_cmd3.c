/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:01:40 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/15 19:28:35 by mogawa           ###   ########.fr       */
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
