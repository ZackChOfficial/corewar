/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:49:21 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/17 10:12:50 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nbrlen(int n)
{
	int l;

	l = 1;
	if (n < 0)
	{
		n *= -1;
		l++;
	}
	while (n > 9)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*nb;
	int		i;
	char	*ng;

	len = ft_nbrlen(n);
	i = len - 1;
	if (n == -2147483648)
		return (ng = ft_strdup("-2147483648"));
	if ((nb = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	if (n < 0)
	{
		nb[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		nb[i--] = (n % 10) + '0';
		n /= 10;
	}
	nb[i] = (n % 10) + '0';
	nb[len] = '\0';
	return (nb);
}
