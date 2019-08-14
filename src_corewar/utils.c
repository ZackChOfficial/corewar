/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 00:40:55 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/30 15:02:33 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int				getfour(t_vm *vm, int adr)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	while (i < 4)
	{
		value = (value << 8) | vm->arena[(adr + i) % MEM_SIZE];
		i++;
	}
	return (value);
}

void			write_four(t_vm *vm, int adr, int val, t_process *ptr)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)&val;
	if (adr < 0)
		adr += 4096;
	while (i < 4)
	{
		vm->arena[(adr + ptr->current_position + i) % MEM_SIZE] = str[3 - i];
		vm->colors[(adr + ptr->current_position + i) % MEM_SIZE] =
ptr->color + 790;
		i++;
	}
}

short			gettwo(t_vm *vm, int adr)
{
	short	value;
	int		i;

	value = 0;
	i = -1;
	while (++i < 2)
		value = (value << 8) | vm->arena[(adr + i) % MEM_SIZE];
	return (value);
}

unsigned char	get_one(unsigned char *str)
{
	return (str[0]);
}

void			copy_data(t_player *dest, t_player *src)
{
	dest->data = src->data;
	dest->id = src->id;
	dest->start = src->start;
	dest->live = src->live;
	dest->last_live = src->last_live;
}
