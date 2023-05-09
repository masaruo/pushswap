/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:38:09 by mogawa            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/07 22:30:26 by mogawa           ###   ########.fr       */
=======
/*   Updated: 2023/01/20 17:17:19 by mogawa           ###   ########.fr       */
>>>>>>> origin/master
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// write n zeroed bytes to the string s.
<<<<<<< HEAD
// 文字列ｓにｎバイト分の０を書き込む
=======
// if n is zero, bzero() does nothing.
>>>>>>> origin/master
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
<<<<<<< HEAD
=======

// actually bzero should use memset.
>>>>>>> origin/master
