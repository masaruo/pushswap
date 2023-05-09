/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:11:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/07 22:41:02 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// count how many digits does 'n' have.
static size_t	ft_putnbr_cnt(int n)
{
	size_t	cnt;

	if (n < 0)
		cnt = 1;
	else
		cnt = 0;
	while (1)
	{
		cnt++;
		n = n / 10;
		if (n == 0)
			break ;
	}
	return (cnt);
}

// append ascii number 'n' to array 'arr'.
void	ft_putnbr_arr(int n, char *arr, size_t *cnt)
{
	if (n < 0)
	{
		arr[*cnt] = '-';
		*cnt = 1;
	}
	if (0 > n && n > -10)
		n = n * -1;
	if (n <= -10)
	{
		ft_putnbr_arr((n / 10) * -1, arr, cnt);
		ft_putnbr_arr((n % 10) * -1, arr, cnt);
	}
	else if (n >= 10)
	{
		ft_putnbr_arr(n / 10, arr, cnt);
		ft_putnbr_arr(n % 10, arr, cnt);
	}
	else if (10 > n && n > -10)
	{	
		arr[*cnt] = n + '0';
		*cnt = *cnt + 1;
	}
}

// returns a string representing provided int 'n'. 
// !FREE必要 数値型ｎを文字列に格納して返す。
char	*ft_itoa(int n)
{
	size_t		digits;
	char		*res;
	size_t		cnt;

	digits = 0;
	digits = ft_putnbr_cnt(n);
	res = malloc(sizeof(char) * (digits + 1));
	if (res == NULL)
		return (NULL);
	cnt = 0;
	ft_putnbr_arr(n, res, &cnt);
	res[cnt] = '\0';
	return (res);
}

// int main(void)
// {
// 	char	*str;

// 	str = ft_itoa(-7);
// 	printf("%s",str);
// 	free(str);
// 	return 1;
// }