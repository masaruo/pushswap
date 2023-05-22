/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:33:08 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 18:06:07 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_xcalloc(size_t count, size_t size, size_t flg, t_stk *stk)
{
	void	*heap;

	heap = ft_calloc(count, size);
	if (heap == NULL)
	{
		if (flg == 2)
			free(stk->init_stk_fr);
		if (flg == 3)
		{
			free(stk->init_stk_fr);
			free(stk->sorted_stk_fr);
		}
		ft_err_exit();
	}
	return (heap);
}

char	*ft_xstrtrim(const char *s, const char *set, bool to_free, t_stk *stk)
{
	char	*res;

	res = ft_strtrim(s, set);
	if (!res)
	{
		if (to_free)
			free(stk->init_stk_fr);
		ft_err_exit();
	}
	return (res);
}

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
		if (i < stk->size - 1 && stk->sorted_stk_fr[i] == \
			stk->sorted_stk_fr[i + 1])
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
		if (stk->init_stk_fr[stk->slit + i] != \
			stk->sorted_stk_fr[stk->slit + i])
			is_sorted = false;
		i++;
	}
	if (is_sorted)
		return (true);
	else
		return (false);
}
