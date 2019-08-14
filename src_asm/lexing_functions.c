/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:14:19 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 23:39:26 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			get_all_arguments(t_asm *assembler, t_instruction *instruction)
{
	int		i;
	char	**table;

	i = 0;
	if (number_of_separators(assembler, instruction) !=
	(assembler->tab[instruction->code - 1].nb_args - 1))
		error_system(5, assembler->error_index);
	table = ft_strsplit(assembler->line + instruction->index, SEPARATOR_CHAR);
	if (!table)
		error_system(5, assembler->error_index);
	while (table[i])
	{
		instruction->arg[i] = table[i];
		i++;
	}
	free(table);
	instruction->nb_args_filled = i;
	if (i != instruction->nb_args)
		error_system(5, assembler->error_index);
	if (!(instruction->arg_type = ft_strnew(instruction->nb_args)))
		exit(0);
}

void			line_pre_parsing(t_asm *assm, char *line)
{
	int i;
	int count;

	count = 0;
	i = 0;
	coun_args(assm, line);
	while (line[i] && line[i] != COMMENT_CHAR && line[i] != ';')
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			line[count] = line[i];
			count++;
		}
		i++;
	}
	line[count] = '\0';
}

t_instruction	*instructions_list(t_asm *assembler, t_instruction *instruction)
{
	if (!instruction)
	{
		if (!(instruction = malloc(sizeof(t_instruction))))
			exit(0);
		assembler->instruction = instruction;
	}
	else
	{
		if (!(instruction->next = malloc(sizeof(t_instruction))))
			exit(0);
		instruction = instruction->next;
	}
	instruction->next = NULL;
	ft_memset(instruction, 0, sizeof(t_instruction));
	return (instruction);
}

int				instruction_lexer(t_asm *assembler, t_instruction *instruction)
{
	get_label_name(assembler, instruction);
	if (get_action(assembler, instruction))
		return (1);
	get_all_arguments(assembler, instruction);
	return (0);
}

int				line_lexer(t_asm *assembler, int fd)
{
	t_instruction *instruction;

	instruction = NULL;
	assembler->exec_code_found = FALSE;
	assembler->line = NULL;
	while (TRUE)
	{
		if (!assembler->empty_label)
			if (get_next_line(fd, &assembler->line) <= 0)
				break ;
		assembler->error_index++;
		assembler->empty_label = 0;
		if (!parsing_line_check(assembler->line))
		{
			assembler->exec_code_found = TRUE;
			instruction = instructions_list(assembler, instruction);
			if (instruction_lexer(assembler, instruction))
				continue ;
			instruction->read_index = assembler->error_index;
		}
		free(assembler->line);
	}
	return (0);
}
