/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:39:52 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/06 12:27:58 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*sc;
	char	*dest;

	sc = (char *)src;
	dest = (char *)dst;
	while (n-- > 0)
		*dest++ = *sc++;
	return (dst);
}
