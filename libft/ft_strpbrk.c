/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 10:59:31 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/17 11:03:45 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str1, const char *str2)
{
	char	*s1;
	char	*s2;
	int		i;
	int		j;

	s1 = (char *)str1;
	s2 = (char *)str2;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
			if (s2[j++] == s1[i])
				return (s1 + i);
		i++;
	}
	return (NULL);
}
