/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:45:31 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/31 18:32:35 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int		get_flag(char *arg, int pos, t_vm *vm)
{
	int	r;

	r = ft_atoi(arg);
	if (r < 0)
		error(17);
	vm->flags[pos] = r;
	return (0);
}

int		check_flags(char *str)
{
	if (!ft_strcmp(str, "-dump") || !ft_strcmp(str, "-d"))
		return (1);
	return (0);
}

int		parse_args(int argc, char **argv, t_vm *vm)
{
	int	i;

	i = 0;
	if (check_flags(argv[i]) == 0)
		return (2);
	else
	{
		if (!ft_strcmp(argv[i], "-dump") || !ft_strcmp(argv[i], "-d"))
		{
			if (++i >= argc || get_flag(argv[i], !ft_strcmp(argv[i - 1],
				"-dump") ? DUMP : DUMP64, vm))
				error(16);
		}
	}
	return (i);
}

void	add_carriage(t_vm *vm, int id, int start)
{
	t_process	*new;
	t_process	*tmp;
	int			i;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		error(22);
	new->player_id = id;
	new->id = vm->id;
	new->color = vm->id++ + 1;
	new->carry = 0;
	new->opcode = 0;
	new->last_live = 0;
	new->cycle_remaining = 0;
	new->current_position = start;
	new->step_over = 0;
	tmp = vm->carriages;
	vm->carriages = new;
	new->next = tmp;
	vm->process++;
	i = 1;
	new->registers[0] = id;
	while (i < REG_NUMBER)
		new->registers[i++] = 0;
}

void	add_players(t_vm *vm)
{
	t_player	*player;

	player = vm->players;
	while (player)
	{
		add_carriage(vm, player->id, player->start);
		if (player->next == NULL)
			vm->winner = player;
		player = player->next;
	}
}
