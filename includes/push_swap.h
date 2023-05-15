/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:18:39 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/15 16:51:51 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stk
{
	size_t	size;
	int		*stk_fr;
	int		*stk_sorted_fr;
	size_t	*stk_abs_fr;
	size_t	slit;
}	t_stk;

t_stk	*ft_mk_stk(char **argv);
void	ft_swap(int *a, int *b);
void	sa(int *stk, int a0, int size);
void	sb(int *stk, int a0, int size);
void	ss(int *stk, int a0, int size);
void	pa(int *stk, int *a0, int size);
void	pb(int *stk, int *a0, int size);
void	ra(int *stk, int a0, int size);
void	rb(int *stk, int a0, int size);
void	rra(int *stk, int a0, int size);
void	rrb(int *stk, int a0, int size);
void	ss(int *stk, int a0, int size);
void	rr(int *stk, int a0, int size);
void	rrr(int *stk, int a0, int size);
void	ft_err_exit(void);
int		*ft_get_arr(char **argv, size_t size);
size_t	ft_get_size(char **argv);
int		ft_atoi_cnt(const char *str, int *j);
void	ft_prefix_cnt(const char *s, int *is_minus, int *j);
int		ft_isspace_cnt(const char c);
void	ft_qsort(int *stk, int left, int right);
void	ft_stk_compress(t_stk *stk);
void	ft_radix_sort(int *stk, int a0val, int *a0ptr, int size);

#endif