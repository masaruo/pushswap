/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_make_stk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:51:13 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 18:25:09 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The atoi() function converts the initial portion of 
// the string pointed to by str to int representation.
int	ft_atoi_cnt(const char *str, int *j)
{
	int			is_minus;
	int			num;
	const char	*s;

	ft_prefix_cnt(str, &is_minus, j);
	num = 0;
	s = str;
	while (s[*j])
	{	
		if (!ft_isdigit(s[*j]))
			ft_err_exit();
		if (num > INT_MAX / 10)
			ft_err_exit();
		num = num * 10;
		if (!is_minus && num > INT_MAX - (s[*j] - '0'))
			ft_err_exit();
		if (is_minus && num - 1 > INT_MAX - (s[*j] - '0'))
			ft_err_exit();
		num = num + (s[*j] - '0');
		*j = *j + 1;
	}
	if (is_minus)
		return ((int)(num * -1));
	else
		return ((int)num);
}

size_t	ft_get_size(char **argv, t_stk *stk)
{
	int		num;
	char	*s;
	int		i;
	int		j;
	int		size;

	i = 1;
	size = 0;
	while (argv[i])
	{
		j = 0;
		s = ft_xstrtrim(argv[i], " , \t", false, stk);
		while (1)
		{
			num = ft_atoi_cnt(s, &j);
			size++;
			if (!s[j])
				break ;
			j++;
		}
		free(s);
		i++;
	}
	return (size);
}

int	*ft_get_arr(char **argv, size_t size, t_stk *stk)
{
	int		*stack;
	char	*s;
	int		i;
	int		j;
	int		n;

	i = 1;
	n = 0;
	stack = ft_xcalloc(size, sizeof(int), 1, stk);
	while (argv[i])
	{
		j = 0;
		s = ft_xstrtrim(argv[i], " , \t", true, stk);
		while (1)
		{
			stack[n] = ft_atoi_cnt(s, &j);
			n++;
			if (!s[j])
				break ;
			j++;
		}
		free(s);
		i++;
	}
	return (stack);
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
