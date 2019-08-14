/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_functions_action.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:14:19 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 22:45:24 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_action(t_asm *assm, t_instruction *instruction)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(assm->tab[i].action, instruction->action))
		{
			instruction->nb_args = assm->tab[i].nb_args;
			instruction->code = assm->tab[i].index;
			return ;
		}
		i++;
	}
	if (instruction->action)
		error_system(4, assm->error_index);
}

int		get_action_line(t_asm *assembler, t_instruction *instruction)
{
	int i;

	i = 0;
	if (instruction->oneline)
		i = instruction->index;
	else
	{
		free(assembler->line);
		while (get_next_line(assembler->fd, &assembler->line))
		{
			assembler->error_index++;
			if (!parsing_line_check(assembler->line))
				break ;
			free(assembler->line);
		}
	}
	return (i);
}

int		get_action(t_asm *assembler, t_instruction *instruction)
{
	int i;
	int j;

	i = get_action_line(assembler, instruction);
	j = 0;
	if (parsing_line_check(assembler->line))
		return (1);
	if (instruction->label && !instruction->oneline &&
		check_empy_label(assembler->line))
	{
		assembler->empty_label = 1;
		return (1);
	}
	i += eliminate_whitespace(assembler->line + i);
	j = i;
	while (assembler->line[j] && assembler->line[j] != ' ' &&
	assembler->line[j] != '\t' && assembler->line[j] != DIRECT_CHAR)
		j++;
	instruction->action = ft_strsub(assembler->line, i, j - i);
	instruction->index = j;
	line_pre_parsing(assembler, assembler->line + j);
	check_action(assembler, instruction);
	return (0);
}
