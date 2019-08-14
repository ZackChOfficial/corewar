/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:03:14 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 22:36:50 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	rm_process(t_vm *vm, t_process *elem, t_process *prev)
{
	if (prev != NULL)
		prev->next = elem->next;
	else
		vm->carriages = elem->next;
	free(elem);
	vm->process--;
}

void	reset(t_vm *vm)
{
	t_player	*player;

	player = vm->players;
	while (player)
	{
		player->live = 0;
		player = player->next;
	}
	if (vm->checks == MAX_CHECKS || vm->lives >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checks = 0;
	}
}

void	check(t_vm *vm)
{
	t_process *process;
	t_process *tmp;
	t_process *prev;

	process = vm->carriages;
	prev = NULL;
	while (process)
	{
		if (process->last_live <= vm->old_cycle ||
				vm->cycles_to_die <= 0)
		{
			tmp = process;
			process = process->next;
			rm_process(vm, tmp, prev);
		}
		else
		{
			prev = process;
			process = process->next;
		}
	}
	reset(vm);
}

void	extract(unsigned char arg, t_process *process, int n)
{
	int				i;
	unsigned char	ar;

	i = -1;
	while (++i < n)
	{
		ar = (arg << (2 * i));
		process->args[i] = ar >> 6;
	}
}

int		check_arg(t_process *ptr, unsigned char arg, int n)
{
	int		i;

	i = -1;
	extract(arg, ptr, n);
	while (++i < n)
		if (ptr->args[i] == 0)
			return (-1);
		else if (ptr->args[i] == 1)
		{
			if ((g_op_tab[ptr->opcode - 1].args[i]
				& T_REG) == 0)
				return (-1);
		}
		else if (ptr->args[i] == 2)
		{
			if ((g_op_tab[ptr->opcode - 1].args[i]
				& T_DIR) == 0)
				return (-1);
		}
		else if (ptr->args[i] == 3)
			if ((g_op_tab[ptr->opcode - 1].args[i]
				& T_IND) == 0)
				return (-1);
	return (0);
}
