/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_make_stk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:51:13 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/23 21:21:57 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_xstr_trim_split(const char *s, const char *set)
{
	char	*trimed_fr;
	char	**splted_fr;

	trimed_fr = ft_strtrim(s, set);
	if (!*trimed_fr)
		ft_err_exit();
	splted_fr = ft_split(trimed_fr, ' ');
	free(trimed_fr);
	if (!splted_fr)
		ft_err_exit();
	return (splted_fr);
}

size_t	ft_get_size(char **argv)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**splt_fr;

	i = 1;
	size = 0;
	while (argv[i])
	{
		splt_fr = ft_xstr_trim_split(argv[i], " ");
		j = 0;
		while (splt_fr[j])
		{
			size++;
			free(splt_fr[j]);
			j++;
		}
		free(splt_fr);
		i++;
	}
	return (size);
}

int	*ft_get_arr(char **argv, size_t size, t_stk *stk)
{
	int		*arr;
	size_t	i;
	size_t	j;
	size_t	n;
	char	**splt_fr;

	i = 1;
	n = 0;
	arr = ft_xcalloc(size, sizeof(int), 1, stk);
	while (argv[i])
	{
		splt_fr = ft_xsplit(argv[i], ' ', arr);
		j = 0;
		while (splt_fr[j])
		{
			arr[n] = ft_xatoi(splt_fr[j]);
			free(splt_fr[j]);
			j++;
			n++;
		}
		free(splt_fr);
		i++;
	}
	return (arr);
}

void	ft_qsort(int *stk, int left, int right)
{
	int	pivot;
	int	l;
	int	r;

	l = left;
	r = right;
	pivot = stk[(left + right) / 2];
	while (1)
	{
		while (stk[l] < pivot)
			l++;
		while (pivot < stk[r])
			r--;
		if (l >= r)
			break ;
		ft_swap_int(&stk[l], &stk[r]);
		l++;
		r--;
	}
	if (left < l - 1)
		ft_qsort(stk, left, l - 1);
	if (r + 1 < right)
		ft_qsort(stk, r + 1, right);
}

void	ft_stk_compress(t_stk *stk)
{
	size_t	i;
	size_t	j;

	ft_chk_dup(stk);
	if (ft_chk_sorted(stk))
		exit(0);
	i = 0;
	while (i < stk->size)
	{
		j = 0;
		while (j < stk->size)
		{
			if (stk->init_stk_fr[j] == stk->sorted_stk_fr[i])
			{
				stk->stk_fr[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}
