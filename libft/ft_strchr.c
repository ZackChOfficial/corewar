/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:36:46 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/07 15:49:22 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*s1;

	s1 = (char *)s;
	ch = (char)c;
	while (*s1)
	{
		if (*s1 == ch)
			return (s1);
		s1++;
	}
	if (c == '\0')
		return (s1);
	return (NULL);
}
