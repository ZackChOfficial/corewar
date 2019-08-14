/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:56:35 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/17 09:18:43 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char				*sc;
	char				*dt;
	int					i;

	sc = (char *)src;
	i = 0;
	dt = (char *)dst;
	while (n > 0)
	{
		dt[i] = sc[i];
		if ((unsigned char)dt[i++] == (unsigned char)c)
			return (&dt[i]);
		n--;
	}
	return (NULL);
}
