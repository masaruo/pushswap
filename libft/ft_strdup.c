/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:11:04 by mogawa            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/07 22:40:35 by mogawa           ###   ########.fr       */
=======
/*   Updated: 2023/01/20 17:49:10 by mogawa           ###   ########.fr       */
>>>>>>> origin/master
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
//! FREE必要 文字列ｓ１をコピーし、メモリー確保した新たな文字列を返す
=======
>>>>>>> origin/master
char	*ft_strdup(const char *s1)
{
	char		*res;
	size_t		n;

	n = ft_strlen(s1);
	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	n = 0;
	while (s1[n])
	{
		res[n] = s1[n];
		n++;
	}
	res[n] = '\0';
	return (res);
}
