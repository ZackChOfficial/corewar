/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:46:43 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/17 10:28:54 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*sc;

	dest = (char *)dst;
	sc = (char *)src;
	if (dest > sc)
		while (len--)
			dest[len] = sc[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
