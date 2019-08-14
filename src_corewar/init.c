/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:45:22 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/30 14:28:45 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	init_arrays(t_vm *vm)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		vm->arena[i] = 0;
		vm->colors[i] = 0;
		i++;
	}
}

void	init(t_vm *vm)
{
	int i;

	if (!(vm->arena = (unsigned char *)
malloc(sizeof(unsigned char) * MEM_SIZE)) ||
!(vm->colors = (int*)malloc(sizeof(int) * MEM_SIZE)))
		error(0);
	init_arrays(vm);
	vm->winner = NULL;
	vm->cycle = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->old_cycle = 0;
	vm->lives = 0;
	vm->process = 0;
	i = 0;
	while (i < 3)
		vm->flags[i++] = -1;
	vm->players = NULL;
	vm->player_nb = 0;
	vm->carriages = NULL;
	vm->checks = 0;
	vm->old = 0;
	vm->id = 0;
}

void	init_arena(t_vm *vm)
{
	int			step;
	int			i;
	int			j;
	int			f;
	t_player	*ptr;

	step = MEM_SIZE / vm->player_nb;
	ptr = vm->players;
	f = 0;
	while (ptr)
	{
		i = f * step;
		j = 0;
		ptr->start = i;
		while (i - (f * step) < (int)ptr->data->prog_size)
		{
			vm->arena[i] = ptr->data->code[j];
			vm->colors[i] = f + 1;
			i++;
			j++;
		}
		f++;
		ptr = ptr->next;
	}
}

void	init_game(t_vm *vm)
{
	t_player	*ptr;
	int			nb;
	t_player	*winner;

	init_arena(vm);
	ptr = vm->players;
	winner = NULL;
	nb = 0;
	while (ptr)
	{
		nb++;
		ptr = ptr->next;
	}
	if (nb > MAX_PLAYERS)
		error(3);
	vm->winner = winner;
}

void	print_startgame(t_vm *vm)
{
	int			i;
	t_player	*ptr;

	i = 0;
	ft_putstr("Introducing contestants...\n");
	while (++i <= vm->player_nb)
	{
		ptr = vm->players;
		ft_putstr("* Player ");
		while (ptr && ptr->id != (i * -1))
			ptr = ptr->next;
		if (ptr != NULL)
		{
			ft_putnbr(ptr->id * -1);
			ft_putstr(", weighing ");
			ft_putnbr(ptr->data->prog_size);
			ft_putstr(" bytes, \"");
			ft_putstr(ptr->data->prog_name);
			ft_putstr("\" (\"");
			ft_putstr(ptr->data->comment);
			ft_putstr("\") !\n");
		}
	}
}
