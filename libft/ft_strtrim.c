/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:36:41 by mogawa            #+#    #+#             */
/*   Updated: 2023/05/07 22:58:27 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

// return s1 with *set of chars removed from head & tail.
//!FREE必要　ｓ１からsetに含まれるそれぞれの文字を頭末から削除し、新たな文字列を返す
char	*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	char		*res_start;
	char const	*s1_start;
	char const	*s1_end;

	if (!s1 || !set)
		return (NULL);
	s1_end = s1;
	while (*s1_end)
		s1_end++;
	s1_end--;
	s1_start = s1;
	while (*s1_start && is_charset(*s1_start, set))
		s1_start++;
	while (s1_end > s1_start && is_charset(*s1_end, set))
		s1_end--;
	res = malloc(sizeof(char) * (s1_end - s1_start + 1 + 1));
	if (res == NULL)
		return (NULL);
	res_start = res;
	while (s1_start <= s1_end)
		*res++ = *s1_start++;
	*res = '\0';
	return (res_start);
}

// malloc size is 2 to adjust from 0 start to 1 start for cnt
// int main(void)
// {
//     char str[] = "aogawa ";
//     char set[] = "ab";
//     char *new;
//     new = ft_strtrim(str, set);
//     printf("%s", new);
//     return 1;
// }