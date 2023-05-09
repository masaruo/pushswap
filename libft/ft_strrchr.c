/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:20:11 by mogawa            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/07 22:58:28 by mogawa           ###   ########.fr       */
=======
/*   Updated: 2023/01/20 18:17:28 by mogawa           ###   ########.fr       */
>>>>>>> origin/master
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locates the last occurrence of c (converted to a char) 
// in the string pointed to by s.
<<<<<<< HEAD
// 文字列ｓの中に文字ｃが最後に現れる場所を返す。なければNULL
=======
>>>>>>> origin/master
char	*ft_strrchr(const char *s, int c)
{
	const char	*str;
	char		chr;

	chr = (char) c;
	str = (const char *) s;
	while (*str)
		str++;
	while (1)
	{
		if (*str == chr)
			return ((char *)str);
		if (str == s)
			break ;
		str--;
	}
	return (NULL);
}
