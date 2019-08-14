/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbattle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:05:54 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 19:46:12 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	exec_loop(t_vm *vm)
{
	t_process	*process;

	process = vm->carriages;
	while (process)
	{
		execute_process(vm, process);
		process = process->next;
	}
}

void	mark_act_pos(t_vm *vm)
{
	t_process *ptr;

	ptr = vm->carriages;
	while (ptr)
	{
		vm->colors[ptr->current_position] = 5 +
		vm->colors[ptr->current_position] % 5;
		ptr = ptr->next;
	}
}

int		update_vm(t_vm *vm)
{
	vm->checks++;
	check(vm);
	vm->lives = 0;
	vm->old_cycle = vm->cycle;
	if (vm->carriages == NULL)
		return (1);
	return (0);
}

void	vbattle_sub(t_vm *vm, t_sdl *data)
{
	while (1)
	{
		manage_events(data);
		check_colors(vm, data->coin);
		if (data->tag == 1)
		{
			mark_act_pos(vm);
			if (data->ttag == -1)
				print_everything(vm, data);
			else
			{
				print_everything(vm, data);
				if (vm->cycle - vm->old_cycle ==
(unsigned int)vm->cycles_to_die || vm->cycles_to_die <= 0)
				{
					if (update_vm(vm))
						break ;
				}
				exec_loop(vm);
				vm->cycle++;
			}
		}
	}
}

void	vbattle(t_vm *vm)
{
	t_sdl		data;

	init_visu(&data);
	init_screen(vm, &data);
	vbattle_sub(vm, &data);
	display_winner(&data, vm);
}
