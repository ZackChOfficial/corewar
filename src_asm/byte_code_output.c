/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_code_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:20:59 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 14:06:37 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char	arg_type_define(t_instruction *instruction,
unsigned char arg_code, int i)
{
	unsigned char c;

	while (instruction->arg_type[i])
	{
		c = 1;
		if (instruction->arg_type[i] == T_REG)
		{
			c = c << ((3 - i) * 2);
			arg_code = arg_code | c;
		}
		else if (instruction->arg_type[i] == T_DIR)
		{
			c = c << ((3 - i) * 2 + 1);
			arg_code = arg_code | c;
		}
		else if (instruction->arg_type[i] == T_IND)
		{
			c = c << ((3 - i) * 2);
			arg_code = arg_code | c;
			c = c << 1;
			arg_code = arg_code | c;
		}
		i++;
	}
	return (arg_code);
}

int				arg_type_coding(t_asm *assm, t_instruction *instruction,
int fd)
{
	unsigned char	arg_code;
	int				i;

	i = 0;
	arg_code = 0;
	if (assm->tab[instruction->code - 1].arg_type)
	{
		arg_code = arg_type_define(instruction, arg_code, i);
		write(fd, &arg_code, 1);
	}
	return (0);
}

void			print_dir_ind(int size_value, int value, int fd)
{
	short short_value;

	short_value = 0;
	if (size_value)
	{
		value = value << 16;
		value = endian_invert_int(value);
		write(fd, &value, 2);
	}
	else
	{
		value = endian_invert_int(value);
		write(fd, &value, 4);
	}
}

void			output_exec_code(t_asm *assm, int fd)
{
	t_instruction	*instruction;
	unsigned char	code;

	code = 0;
	instruction = assm->instruction;
	while (instruction)
	{
		if (instruction->action)
		{
			write(fd, &instruction->code, 1);
			arg_type_coding(assm, instruction, fd);
			arguments_coding(assm, instruction, fd);
		}
		instruction = instruction->next;
	}
}

void			output_manager(t_asm *assm)
{
	int		fd;
	int		i;
	int		x;
	char	*file_name;

	x = 0;
	i = 0xF383EA00;
	file_name = ft_strjoin(assm->file_name, ".cor");
	if ((fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 3)
		error_system(9, -1);
	write(fd, &i, 4);
	output_name(assm, fd);
	write(fd, &x, 4);
	assm->size = endian_invert_int(assm->size);
	write(fd, &assm->size, 4);
	output_comment(assm, fd);
	write(fd, &x, 4);
	output_exec_code(assm, fd);
	free(file_name);
	close(fd);
}
