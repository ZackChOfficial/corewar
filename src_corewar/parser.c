/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:15:56 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/31 18:11:38 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	add_player(t_player **head, t_header *header, int *id)
{
	t_player	*new;
	t_player	*ptr;

	if (!(new = (t_player *)malloc(sizeof(t_player))))
		error(0);
	new->data = header;
	new->id = (*id) * -1;
	new->start = 0;
	new->live = 0;
	new->last_live = 0;
	ptr = *head;
	if (ptr)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*head = new;
	new->next = NULL;
	*id = 0;
}

void	distribute_ids(t_vm *vm, int *t)
{
	t_player	*ptr;
	int			i;

	ptr = vm->players;
	while (ptr)
	{
		if (ptr->id == 0)
		{
			i = 0;
			while (i < vm->player_nb && t[i] != 0)
				i++;
			ptr->id = (i + 1) * (-1);
			t[i] = 1;
		}
		ptr = ptr->next;
	}
}

void	sort_players(t_vm *vm)
{
	t_player	*ielem;
	t_player	*jelem;
	t_player	tmp;

	ielem = vm->players;
	while (ielem)
	{
		jelem = ielem->next;
		while (jelem)
		{
			if (jelem->id > ielem->id)
			{
				copy_data(&tmp, jelem);
				copy_data(jelem, ielem);
				copy_data(ielem, &tmp);
			}
			jelem = jelem->next;
		}
		ielem = ielem->next;
	}
}

void	fill_ids(t_vm *vm, int nb)
{
	int			t[MAX_PLAYERS];
	t_player	*ptr;
	int			i;

	i = 0;
	ptr = vm->players;
	if (vm->players == NULL)
		usage();
	else if (nb != 0)
		error(18);
	while (i < MAX_PLAYERS)
		t[i++] = 0;
	i = 0;
	while (ptr)
	{
		if (ptr->id < 0)
		{
			if (t[(ptr->id * -1) - 1] != 0 || ptr->id > vm->player_nb)
				error(4);
			t[(ptr->id * -1) - 1] = 1;
		}
		ptr = ptr->next;
	}
	distribute_ids(vm, t);
	sort_players(vm);
}

void	parser(int argc, char **argv, t_vm *vm)
{
	int	i;
	int	t;
	int	nb;

	i = 0;
	nb = 0;
	while (++i < argc)
	{
		t = parse_args(argc - i, &argv[i], vm);
		if (!nb && t == 2 && !ft_strcmp(argv[i], "-n"))
		{
			if (++i >= argc || !(nb = get_nb(argv[i])))
				error(1);
		}
		else if (t == 2 || nb)
		{
			add_player(&vm->players, get_file(argv[i]), &nb);
			vm->player_nb++;
			if (vm->player_nb > MAX_PLAYERS)
				error(3);
		}
		i += (t != 2) ? t : 0;
	}
	fill_ids(vm, nb);
}
