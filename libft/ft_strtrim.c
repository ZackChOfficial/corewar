/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:22:51 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/17 10:31:54 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		bg;
	int		end;
	int		i;

	bg = 0;
	i = 0;
	end = ft_strlen(s) - 1;
	while (s[bg] && (s[bg] == ' ' || s[bg] == '\n' || s[bg] == '\t'))
		bg++;
	while ((end >= bg) && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	if ((str = (char *)malloc(sizeof(char) * (end - bg + 1))) == NULL)
		return (NULL);
	while (bg <= end)
		str[i++] = s[bg++];
	str[i] = '\0';
	return (str);
}
