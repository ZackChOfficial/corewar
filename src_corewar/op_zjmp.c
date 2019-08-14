/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:46:36 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 20:27:22 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	ft_zjmp(t_vm *vm, t_process *ptr)
{
	short	next_pos;

	next_pos = mod_adr(gettwo(vm, (ptr->current_position + 1) % MEM_SIZE));
	if (ptr->carry == 1)
	{
		ptr->current_position = (ptr->current_position + next_pos) % MEM_SIZE;
		ptr->step_over = 0;
	}
	else
		ptr->step_over = 3;
}
