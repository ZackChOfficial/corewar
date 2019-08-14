/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:59:03 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 16:13:13 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	step(t_process *process, int type, int dir_size)
{
	if (type == 1)
		process->step_over++;
	else if (type == 2)
		process->step_over += 4 - (2 * dir_size);
	else if (type == 3)
		process->step_over += 2;
}

void	get_lvalue(t_vm *vm, t_process *process, t_arg_value *adr, int type)
{
	short	tmp;

	adr->value = 0;
	adr->error = 0;
	if (type == 1)
	{
		tmp = get_one(vm->arena + (process->current_position
					+ process->step_over) % MEM_SIZE);
		if (tmp > 0 && tmp <= 16)
			adr->value = process->registers[tmp - 1];
		else
			adr->error = 1;
	}
	else if (type == 2)
		adr->value = get_t_dir(vm, process, adr);
	else if (type == 3)
	{
		tmp = gettwo(vm, (process->current_position
					+ process->step_over) % MEM_SIZE);
		adr->value = getfour(vm, (process->current_position
				+ tmp) % MEM_SIZE);
	}
	step(process, type, adr->dir_size);
}

int		get_t_dir(t_vm *vm, t_process *process, t_arg_value *adr)
{
	int	value;

	value = 0;
	if (adr->dir_size == 1)
		value = gettwo(vm, (process->current_position
					+ process->step_over) % MEM_SIZE);
	else
		value = getfour(vm, (process->current_position
					+ process->step_over) % MEM_SIZE);
	return (value);
}

void	get_value(t_vm *vm, t_process *process, t_arg_value *adr, int type)
{
	short	tmp;

	adr->value = 0;
	adr->error = 0;
	if (type == 1)
	{
		tmp = get_one(vm->arena + (process->current_position
					+ process->step_over) % MEM_SIZE);
		if (tmp > 0 && tmp <= 16)
			adr->value = process->registers[tmp - 1];
		else
			adr->error = 1;
	}
	else if (type == 2)
		adr->value = get_t_dir(vm, process, adr);
	else if (type == 3)
	{
		tmp = mod_adr(gettwo(vm, (process->current_position
					+ process->step_over) % MEM_SIZE));
		adr->value = getfour(vm, (process->current_position
				+ tmp) % MEM_SIZE);
	}
	step(process, type, adr->dir_size);
}
