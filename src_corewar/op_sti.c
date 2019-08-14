/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:47:33 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/30 15:00:12 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	get_sti(t_vm *vm, t_process *ptr, t_arg_value *adr2, t_arg_value *adr3)
{
	adr2->dir_size = g_op_tab[vm->arena[ptr->current_position] - 1].dir_size;
	adr3->dir_size = g_op_tab[vm->arena[ptr->current_position] - 1].dir_size;
	get_value(vm, ptr, adr2, ptr->args[1]);
	get_value(vm, ptr, adr3, ptr->args[2]);
}

void	ft_sti(t_vm *vm, t_process *ptr)
{
	unsigned char	arg_type;
	char			reg;
	short			adr;
	t_arg_value		adr2;
	t_arg_value		adr3;

	arg_type = get_one(vm->arena + (ptr->current_position + 1) % MEM_SIZE);
	if (check_arg(ptr, arg_type, 3) == 0)
	{
		ptr->step_over += 2;
		reg = get_one(vm->arena + (ptr->current_position
					+ ptr->step_over) % MEM_SIZE);
		ptr->step_over += 1;
		get_sti(vm, ptr, &adr2, &adr3);
		if (reg > 0 && reg <= 16)
			if (adr2.error == 0 && adr3.error == 0)
			{
				adr = mod_adr_int(adr3.value + adr2.value);
				write_four(vm, adr, ptr->registers[reg - 1],
						ptr);
			}
	}
	else
		ptr->step_over = skip_args(arg_type, 3, 2);
}
