/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:48:28 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 22:12:39 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	get_lldi(t_vm *vm, t_process *ptr, t_arg_value *adr1, t_arg_value *adr2)
{
	ptr->step_over += 2;
	adr1->dir_size = g_op_tab[vm->arena[ptr->current_position] - 1].dir_size;
	adr2->dir_size = g_op_tab[vm->arena[ptr->current_position] - 1].dir_size;
	get_lvalue(vm, ptr, adr1, ptr->args[0]);
	get_lvalue(vm, ptr, adr2, ptr->args[1]);
}

void	ft_lldi(t_vm *vm, t_process *ptr)
{
	unsigned char	arg_type;
	char			reg;
	short			adr;
	t_arg_value		adr1;
	t_arg_value		adr2;

	arg_type = get_one(vm->arena + (ptr->current_position + 1) % MEM_SIZE);
	if (check_arg(ptr, arg_type, 3) == 0)
	{
		get_lldi(vm, ptr, &adr1, &adr2);
		reg = get_one(vm->arena + (ptr->current_position
					+ ptr->step_over) % MEM_SIZE);
		ptr->step_over += 1;
		if (reg > 0 && reg <= 16)
		{
			if (adr1.error == 0 && adr2.error == 0)
			{
				adr = mod_adr_int(adr1.value + adr2.value);
				ptr->registers[reg - 1] = getfour(vm, (ptr->current_position
							+ adr) % MEM_SIZE);
			}
		}
	}
	else
		ptr->step_over = skip_args(arg_type, 3, 2);
}
