/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:04:02 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/17 09:05:01 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*d;
	const	char	*s;
	size_t			n;
	int				dlen;

	d = dst;
	s = src;
	n = size;
	while (n-- > 0 && (*d != '\0'))
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0' && n-- > 1)
		*d++ = *s++;
	*d = '\0';
	return (dlen + ft_strlen(src));
}
