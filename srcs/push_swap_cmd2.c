/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:23:02 by mogawa            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/08 09:46:38 by mogawa           ###   ########.fr       */
=======
/*   Updated: 2023/05/06 19:06:43 by mogawa           ###   ########.fr       */
>>>>>>> origin/master
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
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
=======
// copies len bytes from string src to string dst and returns value of dest.
void	*ft_intmove(int *dst, const int *src, size_t len)
{
	size_t	i;
	int		*pdest;
	int		*psrc;

	if (len == 0)
		return (dst);
	pdest = dst;
	psrc = src;
	i = len;
	if (pdest > psrc)
	{
		while (0 < i)
		{
			pdest[i - 1] = psrc[i - 1];
			i--;
		}	
	}
	else
	{
		i = 0;
		while (i < len)
		{
			pdest[i] = psrc[i];
			i++;
		}
		// ft_memcpy(pdest, psrc, len);
	}
	return (dst);
}


void	ra(int *stk, int a0, int end)
{
	int	tmp;

	tmp = stk[a0];
	ft_memmove(&stk[a0], &stk[a0 + 1], (int)(end - 1 - a0));
	// stk[end - 1] = tmp;
}

void	rb(int *stk, int a0, int end)
{
	int	tmp;

	tmp = stk[0];
	ft_memmove(&stk[0], &stk[1], (int)(a0 - 1));
	stk[a0 - 1] = tmp;
>>>>>>> origin/master
}