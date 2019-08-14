/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:01:14 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/05 15:26:51 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char	ch;
	unsigned	char	*src;

	ch = (unsigned char)c;
	src = (unsigned char*)s;
	while (n-- > 0)
		if (ch == *src++)
			return (--src);
	return (0);
}
