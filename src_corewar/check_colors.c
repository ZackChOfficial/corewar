/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:50:50 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:10:52 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	check_colors(t_vm *vm, Mix_Chunk *coin)
{
	int i;
	int j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			if (vm->colors[j + 64 * i] > 20)
			{
				if (vm->colors[j + 64 * i] > 800)
					Mix_PlayChannel(-1, coin, 0);
				vm->colors[j + 64 * i] -= 20;
			}
			else if (vm->colors[j + 64 * i] < 20 &&
					vm->colors[j + 64 * i] >= 10)
				vm->colors[j + 64 * i] -= 10;
			else if (vm->colors[j + 64 * i] >= 5 &&
					vm->colors[j + 64 * i] < 10)
				vm->colors[j + 64 * i] -= 5;
			j++;
		}
		i++;
	}
}
