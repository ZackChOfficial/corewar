/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:36:24 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/06 10:43:11 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nb_word(char const *s, char c)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (s[i++])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i])
				count++;
		}
	}
	return (++count);
}

static	char	*ft_word(char const *s, int *start, int end)
{
	char	*word;
	int		i;

	i = 0;
	if ((word = (char *)malloc(sizeof(char) * (end - *start + 1))) == NULL)
		return (NULL);
	while (*start < end)
	{
		word[i] = s[*start];
		(*start)++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		ii;
	int		j;

	i = 0;
	ii = 0;
	if ((str = (char **)malloc(sizeof(char*) * (ft_nb_word(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (j != i)
			str[ii++] = ft_word(s, &i, j);
		else
			i++;
	}
	str[ii] = 0;
	return (str);
}
