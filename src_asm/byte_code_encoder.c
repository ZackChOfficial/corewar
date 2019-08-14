/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_code_encoder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:20:59 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 23:11:06 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_dir_ind(char *arg)
{
	int i;
	int found;

	i = 0;
	found = 0;
	if (arg[0] && (arg[0] == '-' || arg[0] == '+'))
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		else
			found = 1;
		i++;
	}
	if (!found)
		return (1);
	return (0);
}

void	t_ind(t_asm *assm, char *argument, t_instruction *instruction, int fd)
{
	int label;
	int value;

	value = 0;
	label = FALSE;
	if (argument[0] && argument[0] == ':' && argument[1])
	{
		value = label_address(assm, argument + 1, instruction->index);
		label = TRUE;
	}
	if (label == FALSE)
		value = ft_atoi(argument);
	if (!label && check_dir_ind(argument))
		error_system(1, instruction->read_index);
	print_dir_ind(1, value, fd);
}

void	t_dir(t_asm *assm, char *argument, t_instruction *instruction, int fd)
{
	int label;
	int value;

	value = 0;
	label = FALSE;
	if (argument[0] && argument[0] == '%' && argument[1] &&
	argument[1] == LABEL_CHAR && argument[2])
	{
		value = label_address(assm, argument + 2, instruction->index);
		label = TRUE;
	}
	if (label == FALSE)
		value = ft_atoi(argument + 1);
	if (!label && check_dir_ind(argument + 1))
		error_system(1, instruction->read_index);
	print_dir_ind(assm->tab[instruction->code - 1].tdir_size, value, fd);
}

void	t_reg(char *argument, int fd, t_instruction *instruction)
{
	int reg;

	reg = 0;
	if (argument[0] && argument[0] == 'r')
		reg = ft_atoi(argument + 1);
	else
		error_system(1, instruction->read_index);
	if (reg == 0)
		error_system(1, instruction->read_index);
	write(fd, &reg, 1);
}

void	arguments_coding(t_asm *assm, t_instruction *instruction, int fd)
{
	int i;

	i = 0;
	while (i < instruction->nb_args)
	{
		if (instruction->arg_type[i] == T_REG)
			t_reg(instruction->arg[i], fd, instruction);
		else if (instruction->arg_type[i] == T_DIR)
			t_dir(assm, instruction->arg[i], instruction, fd);
		else if (instruction->arg_type[i] == T_IND)
			t_ind(assm, instruction->arg[i], instruction, fd);
		i++;
	}
}
