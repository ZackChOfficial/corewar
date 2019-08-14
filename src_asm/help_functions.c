/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:17:56 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 20:32:45 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			next_line_data(char **read, t_asm *assm, int i, int k)
{
	char	*nextline;
	int		j;
	char	*temp;

	j = ft_strlen(*read) - i;
	while (++assm->error_index && get_next_line(assm->fd, &nextline))
	{
		temp = nextline;
		nextline = ft_strjoin(nextline, "\n");
		free(temp);
		temp = *read;
		*read = ft_strjoin(*read, nextline);
		free(temp);
		if ((k = ft_search(nextline, '\"')) >= 0)
		{
			j = j + k - 1;
			free(nextline);
			break ;
		}
		else
			j += ft_strlen(nextline);
		free(nextline);
	}
	(k == -1) ? error_system(0, -1) : i++;
	return (j);
}

char		*g_error_tab[11] =
{"ERROR[name or comment syntax error",
	"ERROR[expected TOKEN argument not found",
	"ERROR[double usage of label name",
	"ERROR[label name is not valid]",
	"ERROR[assembly action is not valid",
	"ERROR[lexical error in arguments",
	"ERROR[address of label not found",
	"ERROR[not enough arguments",
	"ERROR[error in file extension",
	"ERROR[file cannot be opened",
	"ERROR[syntax error at END"};

void		error_system(int error, int line)
{
	ft_putstr(g_error_tab[error]);
	if (line != -1)
	{
		ft_putstr(", line : -[");
		ft_putnbr(line - 1);
		ft_putstr("]- ");
	}
	ft_putstr("]\n");
	exit(0);
}

short		endian_invert_short(short number)
{
	char b0;
	char b1;

	b0 = (number & 0xff) << 8;
	b1 = (number & 65280) >> 8;
	number = 0;
	number = b0 | b1;
	return (number);
}

int			endian_invert_int(int number)
{
	int b0;
	int b1;
	int b2;
	int b3;

	b0 = (number & 0x000000ff) << 24u;
	b1 = (number & 0x0000ff00) << 8u;
	b2 = (number & 0x00ff0000) >> 8u;
	b3 = (number & 0xff000000) >> 24u;
	number = 0;
	number = b0 | b1 | b2 | b3;
	return (number);
}
