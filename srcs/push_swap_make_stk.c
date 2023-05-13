/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_make_stk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:51:13 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/11 18:11:18 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace_cnt(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

void	ft_prefix_cnt(const char *s, int *is_minus, int *j)
{
	while (ft_isspace_cnt(s[*j]))
		*j = *j + 1;
	if (s[*j] == '-')
		*is_minus = -1;
	if (s[*j] == '-' || s[*j] == '+')
		*j = *j + 1;
	return ;
}

// The atoi() function converts the initial portion of 
// the string pointed to by str to int representation.
int	ft_atoi_cnt(const char *str, int *j)
{
	int			is_minus;
	long		num;
	const char	*s;

	is_minus = 0;
	ft_prefix_cnt(str, &is_minus, j);
	num = 0;
	s = str;
	while (s[*j])
	{
		if (num > LONG_MAX / 10)
			ft_err_exit();
		num = num * 10;
		if (!is_minus && num > LONG_MAX - (s[*j] - '0'))
			ft_err_exit();
		if (is_minus && num - 1 > LONG_MAX - (s[*j] - '0'))
			ft_err_exit();
		num = num + (s[*j] - '0');
		*j = *j + 1;
	}
	if (is_minus)
		return ((int)(num * -1));
	else
		return ((int)num);
}

size_t	ft_get_size(char **argv)
{
	int		num;
	char	*s;
	int		i;
	int		j;
	int		n;

	i = 1;
	n = 0;
	while (argv[i])
	{
		j = 0;
		s = ft_strtrim(argv[i], " , \t");
		while (1)
		{
			num = ft_atoi_cnt(s, &j);
			n++;
			if (!s[j])
				break ;
			j++;
		}
		free(s);
		i++;
	}
	return (n);
}

int	*ft_get_arr(char **argv, size_t size)
{
	int		*stk;
	char	*s;
	int		i;
	int		j;
	int		n;

	i = 1;
	n = 0;
	stk = malloc(sizeof(int) * (size + 1));//? + 1 need?
	if (stk == NULL)
		ft_err_exit();
	while (argv[i])
	{
		j = 0;
		s = ft_strtrim(argv[i], " , \t");
		while (1)
		{
			stk[n] = ft_atoi_cnt(s, &j);
			n++;
			if (!s[j])
				break ;
			j++;
		}
		free(s);
		i++;
	}
	stk[n] = NULL;//? need?
	return (stk);
}

void	*ft_qsort(int *stk, int left, int right)
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
		ft_swap(&stk[l], &stk[r]);
		l++;
		r--;
	}
	if (left < l - 1)
		ft_qsort(stk, left, l - 1);
	if (r + 1 < right)
		ft_qsort(stk, r + 1, right);
}
