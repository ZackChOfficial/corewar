/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:34:38 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/30 15:26:46 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	free_vm(t_vm *vm)
{
	t_player	*player;
	t_player	*tmp;
	t_process	*process;
	t_process	*tmp2;

	player = vm->players;
	while (player)
	{
		tmp = player;
		player = player->next;
		free(tmp->data->code);
		free(tmp->data);
		free(tmp);
	}
	process = vm->carriages;
	while (process)
	{
		tmp2 = process;
		process = process->next;
		free(tmp2);
	}
	free(vm->arena);
	free(vm->colors);
	exit(1);
}
