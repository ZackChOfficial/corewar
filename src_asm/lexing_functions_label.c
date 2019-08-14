/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_functions_label.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:14:19 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 23:40:07 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				label_address(t_asm *assm, char *label, int index)
{
	int				size;
	int				label_pos;
	int				index_pos;
	t_instruction	*instruction;

	label_pos = -1;
	index_pos = -1;
	size = 0;
	instruction = assm->instruction;
	while (instruction)
	{
		if (instruction->index == index)
			index_pos = size;
		if (instruction->label && !ft_strcmp(label, instruction->label))
			label_pos = size;
		if (label_pos != -1 && index_pos != -1)
			return (label_pos - index_pos);
		size += instruction->size;
		instruction = instruction->next;
	}
	if (label_pos == -1 || index_pos == -1)
		error_system(6, -1);
	return (0);
}

void			label_repeated_check(t_asm *assm, char *label)
{
	t_instruction *instruction;

	instruction = assm->instruction;
	if (label)
		while (instruction->next)
		{
			if (instruction->label && !ft_strcmp(label, instruction->label))
				error_system(2, assm->error_index);
			instruction = instruction->next;
		}
}

void			label_validation(t_asm *assm, char *label)
{
	int i;
	int j;
	int found;

	i = 0;
	if (label)
	{
		while (label[i])
		{
			j = 0;
			found = FALSE;
			while (LABEL_CHARS[j])
			{
				if (label[i] == LABEL_CHARS[j])
					found = TRUE;
				j++;
			}
			if (found == FALSE)
				error_system(3, assm->error_index);
			i++;
		}
		label_repeated_check(assm, label);
	}
}

void			get_label_name(t_asm *assembler, t_instruction *instruction)
{
	int i;
	int j;

	i = eliminate_whitespace(assembler->line);
	instruction->oneline = TRUE;
	j = i;
	while (assembler->line[j] && assembler->line[j] != ' ' &&
	assembler->line[j] != '\t')
	{
		if (assembler->line[j] == LABEL_CHAR)
		{
			instruction->index = j + 1;
			instruction->label = ft_strsub(assembler->line, i, j - i);
			if (parsing_line_check(assembler->line + j + 1))
				instruction->oneline = FALSE;
			break ;
		}
		else if (assembler->line[j] == DIRECT_CHAR)
			break ;
		j++;
	}
	if (!instruction->label)
		instruction->oneline = TRUE;
	label_validation(assembler, instruction->label);
}

int				check_empy_label(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != DIRECT_CHAR)
	{
		if (line[i] == LABEL_CHAR)
			return (1);
		i++;
	}
	return (0);
}
