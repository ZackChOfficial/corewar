/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:20:28 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/30 14:19:18 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	make_copy(t_vm *vm, t_process *process, int start)
{
	t_process	*new;
	t_process	*tmp;
	int			i;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		error(22);
	new->id = vm->id++;
	new->player_id = process->player_id;
	new->carry = process->carry;
	new->color = process->color;
	new->last_live = process->last_live;
	i = -1;
	while (++i < REG_NUMBER)
		new->registers[i] = process->registers[i];
	new->current_position = start % MEM_SIZE;
	new->cycle_remaining = 0;
	new->step_over = 0;
	tmp = vm->carriages;
	vm->process++;
	vm->carriages = new;
	new->next = tmp;
}

void	ft_fork(t_vm *vm, t_process *process)
{
	int16_t	arg;

	arg = mod_adr(gettwo(vm, (process->current_position + 1) % MEM_SIZE));
	arg += process->current_position;
	process->step_over = 3;
	make_copy(vm, process, arg);
}

void	ft_lfork(t_vm *vm, t_process *process)
{
	int16_t	arg;

	arg = gettwo(vm, (process->current_position + 1) % MEM_SIZE);
	arg += process->current_position;
	process->step_over = 3;
	make_copy(vm, process, arg);
}
