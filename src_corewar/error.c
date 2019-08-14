/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:42:08 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/31 15:47:16 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

char	*g_errors[19] =
{
	"ERROR: malloc error\n",
	"ERROR: \"-n\" need a number\n",
	"ERROR: -n's number must not exceed the number of players\n",
	"ERROR: max numbers of players is 4\n",
	"ERROR: players ids must not be repeated\n",
	"ERROR: some of players executable code is invalid\n",
	"ERROR: can't open the players\n",
	"ERROR: read error (magic code)\n",
	"ERROR: magic code error\n",
	"ERROR: read error (player name)\n",
	"ERROR: read error (NULL after name or comment)\n",
	"ERROR: 4 bytes after name and must be NULL\n",
	"ERROR: player exec code must be < 612 bytes\n",
	"ERROR: read error (player's comment)\n",
	"ERROR: sizeof(exec code) != player size\n",
	"ERROR: problem loading SDL\n",
	"ERROR: -d and -dump take a number of cycle to dump\n",
	"ERROR: the number of cycle must be >= 0\n",
	"ERROR: -n take a champion\n"
};

int		error(int i)
{
	ft_putstr_fd(g_errors[i], 2);
	exit(-1);
}

void	usage(void)
{
	ft_putstr("Usage: ./corewar [-d N -dump N ] -n N <champion1.cor> <...>\n");
	ft_putstr("    -n N      : specify the player's id\n");
	ft_putstr("#### TEXT OUTPUT MODE #############");
	ft_putstr("#############################################\n");
	ft_putstr("    -d N      : Dumps memory after N cycles with 64 ");
	ft_putstr("byte in line then exits\n");
	ft_putstr("    -dump N   : Dumps memory after N cycles with 32 ");
	ft_putstr("byte in line then exits\n");
	ft_putstr("###################################");
	ft_putstr("#############################################\n");
	exit(1);
}
