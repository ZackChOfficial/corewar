/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:32:21 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/31 20:06:01 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/corewar.h"

t_header	*get_t_header(int argc, char **argv)
{
	t_vm		vm;
	t_header	*data;

	init(&vm);
	parser(argc, argv, &vm);
	check_exec_players(&vm);
	if (vm.players == NULL)
		exit(-1);
	data = vm.players->data;
	free(vm.players);
	free(vm.arena);
	free(vm.colors);
	return (data);
}
