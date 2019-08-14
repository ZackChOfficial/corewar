/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:01:15 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 21:34:15 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "disassembler.h"

int		print_arguments_treg(t_header *player, int index)
{
	ft_putstr(" r");
	ft_putnbr(player->code[index]);
	return (1);
}

char	*get_arg_type(char args_type)
{
	int		i;
	int		number;
	char	*args;

	args = ft_strnew(3);
	i = 0;
	while (i < 3)
	{
		args_type = args_type >> 2;
		number = (1 & args_type) | ((1 << 1) & args_type);
		if (number == 1)
			args[2 - i] = T_REG;
		else if (number == 2)
			args[2 - i] = T_DIR;
		else if (number == 3)
			args[2 - i] = T_IND;
		i++;
	}
	return (args);
}

int		read_four_bytes(unsigned char *str)
{
	int out;
	int i;

	i = 0;
	out = 0;
	while (i < 4)
	{
		out += str[i] * (1 << (8 * (3 - i)));
		i++;
	}
	return (out);
}

int		read_two_bytes(t_header *player, int index)
{
	short nb;

	nb = (player->code[index] << 8) | player->code[index + 1];
	return (nb);
}

void	print_player_info(t_header *player)
{
	ft_putstr(NAME_CMD_STRING);
	ft_putstr(" \"");
	ft_putstr(player->prog_name);
	ft_putstr("\"\n");
	ft_putstr(COMMENT_CMD_STRING);
	ft_putstr(" \"");
	ft_putstr(player->comment);
	ft_putstr("\"\n");
}
