/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:38:05 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 15:47:45 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	ft_aff(t_vm *vm, t_process *process)
{
	int8_t	arg;
	int8_t	reg;

	arg = get_one(vm->arena + ((process->current_position + 1) % MEM_SIZE));
	if (arg == 64)
	{
		reg = get_one(vm->arena + ((process->current_position + 2) % MEM_SIZE));
		if (reg > 0 && reg <= 16)
			ft_putchar((char)process->registers[reg - 1]);
		process->step_over = 3;
	}
	else
		process->step_over = skip_args(arg, 1, 4);
}
