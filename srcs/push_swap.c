/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:20:39 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/09 15:08:40 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace_cnt(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static void	ft_prefix_cnt(const char *s, int *is_minus, int *j)
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
static int	ft_atoi_cnt(const char *str, int *j)
{
	int			is_minus;
	long		num;
	const char	*s;

	is_minus = 0;
	ft_prefix_cnt(str, &is_minus, j);
	num = 0;
	s = str;
	while (ft_isdigit(s[*j]))
	{
		if (!is_minus && num > LONG_MAX / 10)
			return ((int)LONG_MAX);
		if (is_minus && num > LONG_MAX / 10)
			return ((int)LONG_MIN);
		num = num * 10;
		if (!is_minus && num > LONG_MAX - (s[*j] - '0'))
			return ((int)LONG_MAX);
		if (is_minus && num - 1 > LONG_MAX - (s[*j] - '0'))
			return ((int)LONG_MIN);
		num = num + (s[*j] - '0');
		*j = *j + 1;
	}
	if (is_minus)
		return ((int)(num * -1));
	else
		return ((int)num);
}

static size_t	ft_get_size(char **argv)
{
	int		num;
	char	*s;
	int		i;
	int		j;
	int		n;

	i = 1;
	n = 0;
	if (!**argv)// todo empty string error ""
		return (NULL);
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

static int	*ft_get_arr(char **argv, size_t size)
{
	int		*stk;
	char	*s;
	int		i;
	int		j;
	int		n;

	i = 1;
	n = 0;
	if (!**argv)// todo empty string error ""
		return (NULL);
	stk = malloc(sizeof(int) * (size + 1));
	if (stk == NULL)
		return (NULL);
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
	stk[n] = NULL;
	return (stk);
}

int	main(int argc, char **argv)
{
	size_t	a0;
	size_t	size;
	int		*stk;

	if (argv > 0)
	{
		int	i = 0;
		size = ft_get_size(argv);
		stk = ft_get_arr(argv, size);
		a0 = 0;
		sa(stk, a0, size);
		pb(stk, &a0, size);
		pb(stk, &a0, size);
		pb(stk, &a0, size);
		printf("a0 = %d\n", a0);
		ra(stk, a0, size);
		i = 0;
		// while (i < size)
		// 	printf("%d\n", stk[i++]);
		rb(stk, a0, size);
		rra(stk, a0, size);
		rrb(stk, a0, size);
		sa(stk, a0, size);
		pa(stk, &a0, size);
		pa(stk, &a0, size);
		pa(stk, &a0, size);
		// printf("=====\n");
		// rb(stk, a0, size);
		// rrr(stk, a0, size);
		// rr(stk, a0, size);
		// rb(stk, a0, size);
		// sb(stk, a0, size);
		// sa(stk, a0, size);
		// sb(stk, a0, size);
		// sb(stk, a0);
		// ss(stk, a0);
		i = 0;
		while (i < size)
			printf("%d\n", stk[i++]);
	}
	return (0);
}

/*
• Global variables are forbidden.
• You have to write a program named push_swap that takes as an argument the stack
a formatted as a list of integers. The first argument should be at the top of the
stack (be careful about the order).
• The program must display the smallest list of instructions possible to sort the stack
a, the smallest number being at the top.
• Instructions must be separated by a ’\n’ and nothing else.
• The goal is to sort the stack with the lowest possible number of operations. During
the evaluation process, the number of instructions found by your program will be
compared against a limit: the maximum number of operations tolerated. If your
program either displays a longer list or if the numbers aren’t sorted properly, your
grade will be 0.
• If no parameters are specified, the program must not display anything and give the
prompt back.
• In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.
------------------------------
BONUS
Write a program named checker that takes as an argument the stack a formatted
as a list of integers. The first argument should be at the top of the stack (be careful
about the order). If no argument is given, it stops and displays nothing.
• It will then wait and read instructions on the standard input, each instruction will
be followed by ’\n’. Once all the instructions have been read, the program has to
execute them on the stack received as an argument.
If after executing those instructions, the stack a is actually sorted and the stack b
is empty, then the program must display "OK" followed by a ’\n’ on the standard
output.
• In every other case, it must display "KO" followed by a ’\n’ on the standard output.
• In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments
are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or
is incorrectly formatted.
*/