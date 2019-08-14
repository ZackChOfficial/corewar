/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_routines3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:17:26 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:08:13 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	print_stats1(t_vm *vm, t_sdl *data)
{
	print_numcycle(vm, data);
	print_numcursors(vm, data);
	print_ctd(vm, data);
}

void	init_coords_l(t_coords *pos2, t_vm *vm, int i, int j)
{
	pos2->c = shex(vm->arena[j + 64 * i]);
	pos2->i = 2 * (j + 64 * i) + 1;
	pos2->id = vm->colors[j + 64 * i] % 10;
	pos2->state = (vm->colors[j + 64 * i] < 10 ? 0 :
	(1 - (vm->colors[j + 64 * i] / 10) % 2) + 1);
}

void	init_coords_r(t_coords *pos1, t_vm *vm, int i, int j)
{
	pos1->c = fhex(vm->arena[j + 64 * i]);
	pos1->i = 2 * (j + 64 * i);
	pos1->id = vm->colors[j + 64 * i] % 10;
	pos1->state = (vm->colors[j + 64 * i] < 10 ? 0 :
	(1 - (vm->colors[j + 64 * i] / 10) % 2) + 1);
}

void	vprint1(t_vm *vm, t_sdl *data)
{
	int			i;
	int			j;
	t_coords	pos1;
	t_coords	pos2;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			init_coords_r(&pos1, vm, i, j);
			init_coords_l(&pos2, vm, i, j);
			draw_half_bite(pos1, data);
			draw_half_bite(pos2, data);
			j++;
		}
		i++;
	}
}

void	vprint(t_vm *vm, t_sdl *data, SDL_Texture **out, int delay)
{
	draw_bgrnd(data, out);
	vprint1(vm, data);
	usleep(delay);
}
