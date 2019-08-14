/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:01:15 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/31 15:56:25 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"
#include "op_tab.h"

int		print_arguments_tdir(t_header *player, int action_index,
int index)
{
	int read;

	read = 0;
	ft_putstr(" %");
	if (g_op_tab[action_index].tdir_size)
	{
		read = 2;
		ft_putnbr(read_two_bytes(player, index));
	}
	else
	{
		read = 4;
		ft_putnbr(read_four_bytes(player->code + index));
	}
	return (read);
}

int		print_arguments(t_header *player, char *args_types, int action_index,
int index)
{
	int i;
	int nb_args;
	int read;

	read = 0;
	nb_args = g_op_tab[action_index].nb_args;
	i = 0;
	while (i < nb_args)
	{
		if (args_types[i] == T_REG)
			read = print_arguments_treg(player, index);
		else if (args_types[i] == T_DIR)
			read = print_arguments_tdir(player, action_index, index);
		else if (args_types[i] == T_IND)
		{
			read = 2;
			ft_putnbr(read_two_bytes(player, index));
		}
		i++;
		index += read;
	}
	ft_putstr("\n\n");
	return (index);
}

int		print_action(t_header *player, int i)
{
	int action_index;

	ft_putchar('\t');
	action_index = player->code[i] - 1;
	ft_putstr(g_op_tab[action_index].action);
	return (action_index);
}

void	print_exec_code(t_header *player)
{
	unsigned int	i;
	char			*args_types;
	int				action_index;

	i = 0;
	while (i < player->prog_size)
	{
		action_index = print_action(player, i);
		if (g_op_tab[action_index].arg_type)
		{
			i++;
			args_types = get_arg_type(player->code[i]);
			i++;
			i = print_arguments(player, args_types, action_index, i);
			free(args_types);
		}
		else
		{
			if (!(args_types = ft_strnew(1)))
				exit(0);
			*args_types = T_DIR;
			i = print_arguments(player, args_types, action_index, ++i);
			free(args_types);
		}
	}
}

int		main(int argc, char **argv)
{
	t_header	*player;

	if (argc == 2)
	{
		player = get_t_header(argc, argv);
		print_player_info(player);
		print_exec_code(player);
		free(player->code);
		free(player);
	}
	else
		ft_putstr("./disassebler <source file>\n");
	return (0);
}
