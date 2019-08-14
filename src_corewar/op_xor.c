/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:46:00 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 22:16:10 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	ft_xor(t_vm *vm, t_process *ptr)
{
	unsigned char	arg_type;
	t_arg_value		adr1;
	t_arg_value		adr2;
	char			reg;

	arg_type = get_one(vm->arena + (ptr->current_position + 1) % MEM_SIZE);
	if (check_arg(ptr, arg_type, 3) == 0)
	{
		ptr->step_over += 2;
		adr1.dir_size = g_op_tab[vm->arena[ptr->current_position] - 1].dir_size;
		adr2.dir_size = g_op_tab[vm->arena[ptr->current_position] - 1].dir_size;
		get_value(vm, ptr, &adr1, ptr->args[0]);
		get_value(vm, ptr, &adr2, ptr->args[1]);
		reg = get_one(vm->arena + (ptr->current_position
					+ ptr->step_over) % MEM_SIZE);
		ptr->step_over++;
		if (reg > 0 && reg <= 16)
			if (adr1.error == 0 && adr2.error == 0)
			{
				ptr->registers[reg - 1] = adr1.value ^ adr2.value;
				ptr->carry = (ptr->registers[reg - 1] == 0) ? 1 : 0;
			}
	}
	else
		ptr->step_over += skip_args(arg_type, 3, 4);
}
