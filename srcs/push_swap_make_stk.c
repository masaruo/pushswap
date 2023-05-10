/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_make_stk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:51:13 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/10 17:43:20 by mogawa           ###   ########.fr       */
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
		// if (!is_minus && num > LONG_MAX / 10)
		if (num > LONG_MAX / 10)
			ft_err_exit();
		// if (is_minus && num > LONG_MAX / 10)
		// 	ft_err_exit();
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
		// if (!argv[i][0])
		// 	ft_err_exit();
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

int	*ft_conv_cordinate(int *stk, size_t size)
{
	int		to_find;
	size_t	i;
	size_t	j;

	// cordinated = malloc(sizeof(int) * (size));
	// if (!cordinated)
	// {
	// 	free(stk);
	// 	ft_err_exit();
	// }
	i = 0;
	j = 0;
	to_find = INT_MIN;
	while (i < size)
	{
		while (to_find < INT_MAX)
		{
			if (stk[i] == to_find)
			{
				stk[i] == j;
				j++;
				break ;
			}
			to_find++;
		}
		i++;
	}
	return (stk);
}