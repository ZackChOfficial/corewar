/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:53:24 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 23:18:01 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	number_of_separators(t_asm *assembler, t_instruction *instruction)
{
	int i;
	int	count;

	count = 0;
	i = instruction->index;
	while (assembler->line[i] && assembler->line[i] != COMMENT_CHAR
	&& assembler->line[i] != ';')
	{
		if (assembler->line[i] == SEPARATOR_CHAR)
			count++;
		i++;
	}
	return (count);
}
