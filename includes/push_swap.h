/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:18:39 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/22 23:47:58 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <stdbool.h>
# define BASE 2

typedef struct s_stk
{
	size_t	size;
	int		*init_stk_fr;
	int		*sorted_stk_fr;
	size_t	*stk_fr;
	size_t	slit;
}	t_stk;

void	ft_mk_stk(char **argv, t_stk *stk);
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
int		*ft_get_arr(char **argv, size_t size, t_stk *stk);
size_t	ft_get_size(char **argv);
void	ft_qsort(int *stk, int left, int right);
void	ft_stk_compress(t_stk *stk);
void	ft_radix_sort(t_stk *stk);
bool	ft_chk_sorted(t_stk *stk);
void	ft_chk_dup(t_stk *stk);
void	ft_sort_ctl(t_stk *stk);
void	ft_sort_triple(t_stk *stk);
void	*ft_xcalloc(size_t count, size_t size, size_t flg, t_stk *stk);
size_t	ft_get_minmax(t_stk *stk, size_t *max, size_t *min);
char	**ft_xsplit(const char *s, char c, int *arr);
int		ft_xatoi(const char *s);

#endif