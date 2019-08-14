/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:13:00 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/04 17:26:24 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char				*dst;
	unsigned	char	src;

	dst = (char *)b;
	src = (unsigned char)c;
	while (len-- > 0)
	{
		*dst++ = src;
	}
	return (b);
}
