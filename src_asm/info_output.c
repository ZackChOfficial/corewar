/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:20:59 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 19:19:30 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	search_for_separator(t_asm *assm, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != COMMENT_CHAR && str[i] != ';')
	{
		if (str[i] == SEPARATOR_CHAR)
			return ;
		if (str[i] != '\t' && str[i] != ' ')
			error_system(1, assm->error_index);
		i++;
	}
}

void	output_name(t_asm *assm, int fd)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = 0;
	while (assm->name[i])
	{
		write(fd, &assm->name[i], 1);
		i++;
		assm->print_index++;
	}
	while (i < PROG_NAME_LENGTH)
	{
		write(fd, &c, 1);
		i++;
	}
}

void	output_comment(t_asm *assm, int fd)
{
	int		i;
	char	c;

	c = 0;
	i = 0;
	while (assm->comment[i])
	{
		write(fd, &assm->comment[i], 1);
		i++;
		assm->print_index++;
	}
	while (i < COMMENT_LENGTH)
	{
		write(fd, &c, 1);
		i++;
		assm->print_index++;
	}
}
