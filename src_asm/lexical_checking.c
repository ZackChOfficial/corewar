/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:21:24 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 15:24:33 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_reg(t_asm *assm, t_instruction *instruction, int i)
{
	if (assm->tab[instruction->code - 1].argum.arg[i] & T_REG &&
(check_register(instruction->arg[i])))
	{
		instruction->arg_type[i] = T_REG;
		instruction->size += 1;
	}
	else
		error_system(5, instruction->read_index);
}

void	check_dir(t_asm *assm, t_instruction *instruction, int i)
{
	if (assm->tab[instruction->code - 1].argum.arg[i] & T_DIR)
	{
		instruction->arg_type[i] = T_DIR;
		if (assm->tab[instruction->code - 1].tdir_size)
			instruction->size += 2;
		else
			instruction->size += 4;
	}
	else
		error_system(5, instruction->read_index);
}

void	check_ind(t_asm *assm, t_instruction *instruction, int i)
{
	if (assm->tab[instruction->code - 1].argum.arg[i] & T_IND)
	{
		instruction->arg_type[i] = T_IND;
		instruction->size += 2;
	}
	else
		error_system(5, instruction->read_index);
}

void	check_instruction_args(t_asm *assm, t_instruction *instruction)
{
	int i;

	i = 0;
	while (i < instruction->nb_args)
	{
		if (*instruction->arg[i] == DIRECT_CHAR)
			check_dir(assm, instruction, i);
		else if (*instruction->arg[i] == 'r')
			check_reg(assm, instruction, i);
		else
			check_ind(assm, instruction, i);
		i++;
	}
}

void	check_instruction(t_asm *assm)
{
	int				index;
	t_instruction	*instruction;

	index = 0;
	instruction = assm->instruction;
	while (instruction)
	{
		if (instruction->action)
		{
			instruction->index = index;
			instruction->size += 1;
			if (assm->tab[instruction->code - 1].arg_type)
				instruction->size += 1;
			check_instruction_args(assm, instruction);
			assm->size += instruction->size;
		}
		instruction = instruction->next;
		index++;
	}
}
