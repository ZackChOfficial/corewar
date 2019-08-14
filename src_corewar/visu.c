/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:24:36 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/31 18:36:00 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

t_header	*get_t_header(int argc, char **argv)
{
	t_vm		vm;
	t_player	*player;

	init(&vm);
	parser(argc, argv, &vm);
	player = vm.players;
	return (player->data);
}

int			main(int argc, char **argv)
{
	t_vm		vm;

	init(&vm);
	parser(argc, argv, &vm);
	init_game(&vm);
	add_players(&vm);
	check_exec_players(&vm);
	vbattle(&vm);
	free_vm(&vm);
	return (0);
}
