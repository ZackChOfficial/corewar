/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:15:41 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/05 17:04:36 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*begin;
	const char	*t;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		begin = haystack;
		t = needle;
		if (*begin != *t)
		{
			haystack++;
			continue;
		}
		while (1337)
		{
			if (*t == '\0')
				return ((char *)haystack);
			if (*begin++ != *t++)
				break ;
		}
		haystack++;
	}
	return (NULL);
}
