/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:51:03 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 15:46:00 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

short	mod_adr(short c)
{
	int sign;

	sign = c < 0 ? -1 : 1;
	c *= sign;
	c %= IDX_MOD;
	c *= sign;
	return (c);
}

int		mod_adr_int(int c)
{
	int sign;

	sign = c < 0 ? -1 : 1;
	c *= sign;
	c %= IDX_MOD;
	c *= sign;
	return (c);
}
