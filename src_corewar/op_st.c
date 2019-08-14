/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:28:23 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/30 15:01:11 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	ft_st(t_vm *vm, t_process *ptr)
{
	unsigned char	arg_type;
	char			reg1;
	char			reg2;
	short			adr;

	arg_type = get_one(vm->arena + (ptr->current_position + 1) % MEM_SIZE);
	if (check_arg(ptr, arg_type, 2) == 0)
	{
		ptr->step_over += 2;
		reg1 = get_one(vm->arena + (ptr->current_position
					+ ptr->step_over) % MEM_SIZE);
		ptr->step_over++;
		reg2 = get_one(vm->arena + (ptr->current_position
					+ ptr->step_over) % MEM_SIZE);
		adr = mod_adr(gettwo(vm, (ptr->current_position
						+ ptr->step_over) % MEM_SIZE));
		ptr->step_over += (ptr->args[1] == 1) ? 1 : 2;
		if (reg1 > 0 && reg1 <= 16 && ptr->args[1] == 3)
			write_four(vm, adr, ptr->registers[reg1 - 1],
					ptr);
		else if (reg1 > 0 && reg1 <= 16 && reg2 > 0 && reg2 <= 16)
			ptr->registers[reg2 - 1] = ptr->registers[reg1 - 1];
	}
	else
		ptr->step_over = skip_args(arg_type, 2, 4);
}
