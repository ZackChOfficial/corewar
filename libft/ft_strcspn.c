/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 10:53:55 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/17 10:56:31 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *str1, const char *str2)
{
	char	*s1;
	char	*s2;
	size_t	len;

	s1 = (char *)str1;
	s2 = (char *)str2;
	len = 0;
	while (s1[len] != *s2)
		len++;
	return (len);
}
