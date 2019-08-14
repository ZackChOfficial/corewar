/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:23:42 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 22:11:45 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	ft_ld(t_vm *vm, t_process *ptr)
{
	unsigned char	arg_type;
	t_arg_value		adr1;
	char			reg;

	arg_type = get_one(vm->arena + ((ptr->current_position + 1) % MEM_SIZE));
	if (check_arg(ptr, arg_type, 2) == 0)
	{
		ptr->step_over += 2;
		adr1.dir_size = g_op_tab[vm->arena[ptr->current_position] - 1].dir_size;
		get_value(vm, ptr, &adr1, ptr->args[0]);
		reg = get_one(vm->arena +
				(ptr->current_position + ptr->step_over) % MEM_SIZE);
		ptr->step_over++;
		if (reg > 0 && reg <= 16 && adr1.error == 0)
		{
			ptr->registers[reg - 1] = adr1.value;
			if (adr1.value == 0)
				ptr->carry = 1;
			else
				ptr->carry = 0;
		}
	}
	else
		ptr->step_over = skip_args(arg_type, 2, 4);
}
