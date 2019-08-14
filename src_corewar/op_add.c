/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:28:59 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 20:21:37 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	ft_add(t_vm *vm, t_process *ptr)
{
	unsigned char	arg_type;
	char			reg[3];

	arg_type = get_one(vm->arena + (ptr->current_position + 1) % MEM_SIZE);
	if (check_arg(ptr, arg_type, 3) == 0)
	{
		ptr->step_over += 2;
		reg[0] = get_one(vm->arena + (ptr->current_position + 2) % MEM_SIZE);
		reg[1] = get_one(vm->arena + (ptr->current_position + 3) % MEM_SIZE);
		reg[2] = get_one(vm->arena + (ptr->current_position + 4) % MEM_SIZE);
		if (reg[0] > 0 && reg[0] <= 16 && reg[1] > 0 && reg[1] <= 16
				&& reg[2] > 0 && reg[1] <= 16)
		{
			ptr->registers[reg[2] - 1] = ptr->registers[reg[0] - 1]
									+ ptr->registers[reg[1] - 1];
			ptr->carry = (ptr->registers[reg[2] - 1] == 0) ? 1 : 0;
		}
		ptr->step_over += 3;
	}
	else
		ptr->step_over = skip_args(arg_type, 3, 4);
}
