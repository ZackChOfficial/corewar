/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:05:26 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/07 15:47:36 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;
	size_t	j;
	char	*bg;

	l = ft_strlen(needle);
	while (*haystack && len > 0)
	{
		bg = (char *)needle;
		j = ft_strlen(haystack);
		if (j < l || l > len)
			return (NULL);
		if (!(ft_memcmp(haystack, needle, l)))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
