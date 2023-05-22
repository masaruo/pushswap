/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:39:16 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 10:38:10 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_err_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(-1);
}

void	ft_chk_dup(t_stk *stk)
{
	size_t	i;

	i = 0;
	while (i < stk->size)
	{
		if (i < stk->size - 1 && stk->sorted_stk_fr[i] 
			== stk->sorted_stk_fr[i + 1])
			ft_err_exit();
		i++;
	}
}

bool	ft_chk_sorted(t_stk *stk)
{
	size_t	i;
	bool	is_sorted;

	i = 0;
	is_sorted = true;
	while (i < stk->size)
	{
		if (stk->init_stk_fr[stk->slit + i] != stk->sorted_stk_fr[stk->slit + i])
			is_sorted = false;
		i++;
	}
	if (is_sorted)
		return (true);
	else
		return (false);
}
