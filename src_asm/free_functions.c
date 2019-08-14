/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:17:56 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/29 20:18:27 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_register(char *reg)
{
	int		i;
	int		number;

	i = 0;
	number = ft_atoi(reg + 1);
	if (number < 1 || number > REG_NUMBER)
		return (0);
	while (reg[i])
	{
		if (i != 0 && !ft_isdigit(reg[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_instruction(t_instruction *instruction)
{
	int				i;
	t_instruction	*old;

	while (instruction)
	{
		i = 0;
		while (i < instruction->nb_args_filled)
		{
			free(instruction->arg[i]);
			i++;
		}
		if (instruction->label)
			free(instruction->label);
		if (instruction->action)
			free(instruction->action);
		if (instruction->arg_type)
			free(instruction->arg_type);
		old = instruction;
		instruction = instruction->next;
		free(old);
	}
}

void	free_function(t_asm *assm)
{
	t_instruction *instruction;

	instruction = assm->instruction;
	if (assm->name)
		free(assm->name);
	if (assm->comment)
		free(assm->comment);
	if (assm->file_name)
		free(assm->file_name);
	free_instruction(instruction);
	free(assm);
}
