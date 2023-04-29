/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:20:39 by mogawa            #+#    #+#             */
/*   Updated: 2023/04/28 23:23:12 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sa(int *stk, int atop)
{
	int	tmp;

	tmp = stk[atop];
	stk[atop] = stk[atop - 1];
	stk[atop - 1] = tmp;
}

void	sb(int *stk, int atop)
{
	int	tmp;

	tmp = stk[atop + 1];
	stk[atop + 1] = stk[atop + 2];
	stk[attop + 1] = tmp;
}

void	ss(int *stk, int b0)
{
	sa(stk, b0);
	sb(stk, b0);
}

void	pa()

// 関数ポインター
void	ft_pushswap(int *stk, (*stk)func(*stk))
{
	
}

int	main(int argc, char **argv)
{
	size_t	n;
	int		*stk;

	if (argv > 0)
	{
		stk = malloc(sizeof(int) * argc);
		n = 0;
		while(n + 1 < argc)
		{
			stk[n] = ft_atoi(argv[n + 1]);
			n++;
		}
		stk[n] = NULL;
		ft_pushswap(stk);
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