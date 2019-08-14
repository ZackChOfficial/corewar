/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:19:28 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/31 16:12:03 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_finish_status(char *file_name)
{
	ft_putstr("Writing output program to ");
	ft_putstr(file_name);
	ft_putstr(".cor");
	ft_putstr("\n");
}

void	info_table(t_asm *assm)
{
	int i;

	i = 0;
	while (i < 17)
	{
		assm->tab[i] = g_op_tab[i];
		i++;
	}
}

void	print_usage(int argc, char *prog)
{
	if (argc == 1)
	{
		ft_putstr("Usage: ");
		ft_putstr(prog);
		ft_putstr(" <sourcefile.s>\n");
	}
}

void	parsing_file(t_asm *assembler)
{
	champion_info_parser(assembler);
	prog_info_validation(assembler);
	info_table(assembler);
	line_lexer(assembler, assembler->fd);
}

int		main(int argc, char *argv[])
{
	t_asm *assembler;

	if (argc > 1)
	{
		if (!(assembler = malloc(sizeof(t_asm))))
			exit(0);
		ft_memset(assembler, 0, sizeof(t_asm));
		if ((assembler->fd = open(argv[argc - 1], O_RDONLY)) < 3)
			error_system(9, -1);
		get_file_name(assembler, argv[argc - 1]);
		parsing_file(assembler);
		if (assembler->exec_code_found && assembler->instruction)
		{
			close(assembler->fd);
			check_instruction(assembler);
			output_manager(assembler);
		}
		else
			error_system(10, -1);
		print_finish_status(assembler->file_name);
		free_function(assembler);
	}
	print_usage(argc, argv[0]);
	return (0);
}
