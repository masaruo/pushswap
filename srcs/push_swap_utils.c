/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:33:08 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/18 13:12:52 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_xcalloc(size_t count, size_t size)
{
	void	*heap;

	heap = ft_calloc(count, size);
	if (heap == NULL)
	{
		// free all
		exit(-1);
	}
	return (heap);
}
