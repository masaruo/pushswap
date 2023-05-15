/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:20:42 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/15 18:36:59 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stk stk)
{
	
}

// void	sa(int *stk, int a0, int size)
// {
// 	if (a0 <= size - 2)
// 	{
// 		ft_swap(&stk[a0], &stk[a0 + 1]);
// 	}
// }

void	sb(int *stk, int a0, int size)
{
	if (2 <= a0)
	{
		ft_swap(&stk[a0 - 1], &stk[a0 - 2]);
	}
}

void	pa(int *stk, int *a0, int size)
{
	if (1 <= *a0)
	{
		*a0 = *a0 - 1;
	}
}

void	pb(int *stk, int *a0, int size)
{
	if (*a0 != size)
	{
		*a0 = *a0 + 1;
	}
}
