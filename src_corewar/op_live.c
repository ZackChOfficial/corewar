/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:21:12 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/30 01:36:52 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int		skip_args(int arg_type, int n, int dir_s)
{
	int	out;
	int	tmp;
	int	j;

	out = 0;
	j = 0;
	while (j < n)
	{
		tmp = arg_type >> (6 - 2 * j);
		arg_type -= arg_type >> (6 - 2 * j) * 1 << (6 - 2 * j);
		if (tmp != 0)
		{
			if (tmp == 2)
				out += dir_s;
			else
				out += (tmp == 1) ? 1 : 2;
		}
		j++;
	}
	return (out + 2);
}

void	ft_live(t_vm *vm, t_process *ptr)
{
	int			player;
	t_player	*tmp;

	player = getfour(vm, (ptr->current_position + 1) % MEM_SIZE);
	tmp = vm->players;
	while (tmp != NULL)
	{
		if (tmp->id == player)
		{
			vm->colors[ptr->current_position] = tmp->id * -1 + 800;
			tmp->last_live = vm->cycle + 1;
			vm->winner = tmp;
			tmp->live++;
			break ;
		}
		tmp = tmp->next;
	}
	ptr->last_live = vm->cycle;
	vm->lives++;
	ptr->step_over = 5;
}
