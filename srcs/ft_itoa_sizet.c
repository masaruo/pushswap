/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_sizet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:11:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/18 13:39:29 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // count how many digits does 'n' have.
// static size_t	ft_putnbr_cnt(int n)
// {
// 	size_t	cnt;

// 	if (n < 0)
// 		cnt = 1;
// 	else
// 		cnt = 0;
// 	while (1)
// 	{
// 		cnt++;
// 		n = n / 10;
// 		if (n == 0)
// 			break ;
// 	}
// 	return (cnt);
// }

// append ascii number 'n' to array 'arr'.
static void	ft_putnbr_arr(size_t n, char *arr, size_t *cnt, size_t base)
{
	if (n >= base)
	{
		ft_putnbr_arr(n / base, arr, cnt, base);
		ft_putnbr_arr(n % base, arr, cnt, base);
	}
	else
	{	
		arr[*cnt] = n + '0';
		*cnt = *cnt + 1;
	}
}

// returns a string representing provided int 'n'. 
// !FREE必要 数値型ｎを文字列に格納して返す。
void	ft_itoa_sizet(t_stk *stk)
{
	size_t	cnt;
	size_t	i;
	size_t	base;
	size_t	n;
	char	*bits;

	base = 3;
	i = 0;
	while (i < stk->size)
	{
		cnt = 0;
		n = stk->s[i].dt;
		bits = stk->s[i].bit;
		ft_putnbr_arr(n, bits, &cnt, base);
		i++;
	}
}

// int main(void)
// {
// 	char	*str;

// 	str = ft_itoa_sizet(4294967295);
// 	printf("%s",str);
// 	free(str);
// 	return 1;
// }