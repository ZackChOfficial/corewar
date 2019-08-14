/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:51:18 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/31 18:33:22 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int		valid_opcode(unsigned char op)
{
	return ((op >= 1 && op <= 16) ? 1 : 0);
}

void	opcode_execute(t_vm *vm, t_process *process)
{
	int8_t	op;

	if (valid_opcode(process->opcode) == 0)
		process->step_over = 1;
	else
	{
		op = process->opcode;
		g_op_tab[op - 1].fun(vm, process);
	}
}

void	execute_process(t_vm *vm, t_process *ptr)
{
	if (ptr->cycle_remaining == 0)
	{
		ptr->opcode = vm->arena[ptr->current_position];
		if (valid_opcode(ptr->opcode))
			ptr->cycle_remaining = g_op_tab[ptr->opcode - 1].cycle_remaining;
		else
			ptr->cycle_remaining = 0;
	}
	if (ptr->cycle_remaining > 0)
		ptr->cycle_remaining--;
	if (ptr->cycle_remaining == 0)
	{
		opcode_execute(vm, ptr);
		if (ptr->current_position + ptr->step_over < 0)
			ptr->current_position += MEM_SIZE + ptr->step_over;
		else
			ptr->current_position = (ptr->current_position +
					ptr->step_over) % MEM_SIZE;
		ptr->opcode = 0;
		ptr->step_over = 0;
	}
}

void	check_dump(t_vm *vm)
{
	if (vm->flags[DUMP] > -1)
	{
		if (vm->cycle == (unsigned int)vm->flags[DUMP])
			printit(vm, 32);
	}
	else if (vm->flags[DUMP64] > -1)
		if (vm->cycle == (unsigned int)vm->flags[DUMP64])
			printit(vm, 64);
}

void	battle(t_vm *vm)
{
	t_process	*process;

	print_startgame(vm);
	while (1)
	{
		check_dump(vm);
		if (vm->cycle - vm->old_cycle == (unsigned int)vm->cycles_to_die ||
				vm->cycles_to_die <= 0)
		{
			vm->checks++;
			check(vm);
			vm->lives = 0;
			vm->old_cycle = vm->cycle;
			if (vm->carriages == NULL)
				break ;
		}
		process = vm->carriages;
		while (process)
		{
			execute_process(vm, process);
			process = process->next;
		}
		vm->cycle++;
	}
}
