/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:47:25 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/07 09:42:29 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	str = (char *)s;
	if (!(*s))
	{
		if (*str == c)
			return (str);
	}
	else
	{
		len = ft_strlen(str);
		if (c == '\0')
			return (str + len);
		while (len >= 0)
		{
			len--;
			if (str[len] == c)
				return (str + len);
		}
	}
	return (NULL);
}
