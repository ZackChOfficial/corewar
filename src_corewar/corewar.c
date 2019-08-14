/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:24:36 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/31 15:37:26 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int		main(int argc, char **argv)
{
	t_vm		vm;

	init(&vm);
	parser(argc, argv, &vm);
	if (vm.players == NULL)
		usage();
	init_game(&vm);
	add_players(&vm);
	check_exec_players(&vm);
	battle(&vm);
	ft_putstr("Contestant ");
	ft_putnbr(vm.winner->id * -1);
	ft_putstr(", \"");
	ft_putstr(vm.winner->data->prog_name);
	ft_putstr("\", has won !\n");
	free_vm(&vm);
	return (0);
}
