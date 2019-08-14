/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:03:20 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/31 21:36:14 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	print_byte(unsigned char c)
{
	int	tmp;

	tmp = c / 16;
	ft_putchar(tmp >= 10 ? 'a' + tmp - 10 : '0' + tmp);
	tmp = c % 16;
	ft_putchar(tmp >= 10 ? 'a' + tmp - 10 : '0' + tmp);
}

void	printit(t_vm *vm, int n)
{
	int				i;
	int				j;
	int				m;
	unsigned char	x;

	i = 0;
	m = (n == 64) ? 64 : 128;
	while (i < m)
	{
		ft_putstr("0x");
		x = ((i * n) << 16) >> 24;
		print_byte(x);
		x = ((i * n) << 24) >> 24;
		print_byte(x);
		ft_putstr(" :");
		j = -1;
		while (++j < n)
		{
			ft_putchar(' ');
			print_byte(vm->arena[j + (i * n)]);
		}
		ft_putchar('\n');
		i++;
	}
	exit(1);
}
