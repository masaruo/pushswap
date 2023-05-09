/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:52:54 by mogawa            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/07 22:58:30 by mogawa           ###   ########.fr       */
=======
/*   Updated: 2023/01/20 18:16:48 by mogawa           ###   ########.fr       */
>>>>>>> origin/master
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// compare strings s1 and s2 with NOT more than n chars.
<<<<<<< HEAD
// 文字列ｓ１とｓ２を比較をｎ文字分比較。ヌル文字まで比較継続。
=======
// l28 check empty strings & l38 check \0 as well.
>>>>>>> origin/master
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (n == 0)
		return (0);
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i] || !str1[i] || !str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}
