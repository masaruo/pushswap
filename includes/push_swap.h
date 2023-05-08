/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:18:39 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/08 11:46:24 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft.h"

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

#endif