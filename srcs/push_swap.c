/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:20:39 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/20 10:13:22 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_mk_stk(char **argv, t_stk *stk)
{
	stk->size = ft_get_size(argv);
	stk->stk_fr = ft_get_arr(argv, stk->size);
	stk->stk_sorted_fr = malloc(sizeof(int) * stk->size);//todo error
	stk->stkf = malloc(sizeof(size_t) * stk->size);//todo error
	// stk->s = ft_xcalloc(stk->size, sizeof(t_elm));
	ft_memmove(stk->stk_sorted_fr, stk->stk_fr, sizeof(int) * stk->size);
	ft_qsort(stk->stk_sorted_fr, 0, stk->size - 1);
	ft_stk_compress(stk);
	stk->slit = 0;
}

int	main(int argc, char **argv)
{
	t_stk	stk;

	if (argc > 1)
	{
		ft_mk_stk(argv, &stk);
		ft_radix_sort(&stk);
		free(stk.stkf);
	}
	else if (argc == 1)
		return (0);
	else
		ft_err_exit();
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