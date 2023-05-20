/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:18:39 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/20 13:51:50 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# define BASE 2

typedef struct s_stk
{
	size_t	size;
	int		*stk_fr;
	int		*stk_sorted_fr;
	size_t	*stkf;
	size_t	slit;
}	t_stk;

void	*ft_mk_stk(char **argv, t_stk *stk);
void	ft_swap_sizet(size_t *a, size_t *b);
void	ft_swap_int(int *a, int *b);
void	sa(t_stk *stk);
void	sb(t_stk *stk);
void	ss(t_stk *stk);
void	pa(t_stk *stk);
void	pb(t_stk *stk);
void	ra(t_stk *stk);
void	rb(t_stk *stk);
void	rra(t_stk *stk);
void	rrb(t_stk *stk);
void	ss(t_stk *stk);
void	rr(t_stk *stk);
void	rrr(t_stk *stk);
void	ft_err_exit(void);
int		*ft_get_arr(char **argv, size_t size);
size_t	ft_get_size(char **argv);
int		ft_atoi_cnt(const char *str, int *j);
void	ft_prefix_cnt(const char *s, int *is_minus, int *j);
int		ft_isspace_cnt(const char c);
void	ft_qsort(int *stk, int left, int right);
void	ft_stk_compress(t_stk *stk);
void	ft_radix_sort(t_stk *stk);

#endif