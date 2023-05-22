/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:20:39 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 19:41:30 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mk_stk(char **argv, t_stk *stk)
{
	stk->size = ft_get_size(argv);
	stk->init_stk_fr = ft_get_arr(argv, stk->size, stk);
	stk->sorted_stk_fr = ft_xcalloc(stk->size, sizeof(int), 2, stk);
	stk->stk_fr = ft_xcalloc(stk->size, sizeof(size_t), 3, stk);
	ft_memmove(stk->sorted_stk_fr, stk->init_stk_fr, sizeof(int) * stk->size);
	ft_qsort(stk->sorted_stk_fr, 0, stk->size - 1);
	ft_stk_compress(stk);
	stk->slit = 0;
}

int	main(int argc, char **argv)
{
	t_stk	stk;

	if (argc > 1)
	{
		ft_mk_stk(argv, &stk);
		ft_sort_ctl(&stk);
		free(stk.stk_fr);
		free(stk.sorted_stk_fr);
		free(stk.init_stk_fr);
	}
	else if (argc == 1)
		return (0);
	else
		ft_err_exit();
	return (0);
}
