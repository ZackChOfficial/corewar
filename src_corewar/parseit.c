/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:36:46 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 22:16:55 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int		get_arg(unsigned char *d, int *i, int j, uint8_t *arg)
{
	int	arg_size;

	arg_size = 0;
	if (arg[j] == 1)
	{
		if ((g_op_tab[d[*i] - 1].args[j] & T_REG) == 0)
			return (-1);
		if (d[*i + arg_size] < 1 || d[*i + arg_size] > 16)
			return (-1);
		arg_size++;
	}
	else if (arg[j] == 2)
	{
		if ((g_op_tab[d[*i] - 1].args[j] & T_DIR) == 0)
			return (-1);
		arg_size += 4 - (2 * g_op_tab[d[*i] - 1].dir_size);
	}
	else if (arg[j] == 3)
	{
		if ((g_op_tab[d[*i] - 1].args[j] & T_IND) == 0)
			return (-1);
		arg_size += 2;
	}
	return (arg_size);
}

int		check_args(unsigned char *d, int *i, int size)
{
	uint8_t	arg[3];
	uint8_t	arg_size;
	int		j;
	int		r;

	if (*i + 1 >= size)
		return (-1);
	arg[0] = (d[(*i) + 1] & FIRST_ARG) >> 6;
	arg[1] = (d[(*i) + 1] & SECOND_ARG) >> 4;
	arg[2] = (d[(*i) + 1] & THIRD_ARG) >> 2;
	j = -1;
	arg_size = 2;
	while (++j < 3)
	{
		if ((r = get_arg(d, i, j, arg)) == -1)
			return (-1);
		arg_size += r;
	}
	*i += arg_size;
	return (0);
}

int		check_exec_player(t_player *player)
{
	int				i;
	unsigned char	*d;

	i = 0;
	d = player->data->code;
	while (i < (int)player->data->prog_size)
	{
		if (d[i] < 1 || d[i] > 16)
			return (-1);
		if (g_op_tab[d[i] - 1].have_args == 0)
			i += 1 + 4 - (2 * g_op_tab[d[i] - 1].dir_size);
		else if (check_args(d, &i, player->data->prog_size) == -1)
			return (-1);
	}
	return (0);
}

void	check_exec_players(t_vm *vm)
{
	t_player	*player;

	player = vm->players;
	while (player)
	{
		if (check_exec_player(player) == -1)
			error(5);
		player = player->next;
	}
}
