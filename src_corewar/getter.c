/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:52:59 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/29 22:34:36 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int			get_nb(char *nbr)
{
	int	i;
	int	n;

	i = 0;
	n = ft_atoi(nbr);
	if (n < 1 || n > MAX_PLAYERS)
		error(2);
	return (n);
}

int			get_int32(int fd)
{
	uint8_t				b[4];
	unsigned int		r;
	int					i;

	r = 0;
	i = 0;
	if (read(fd, b, 4) < 4)
		error(7);
	while (i < 4)
	{
		r <<= 8;
		r |= b[i++];
	}
	return (r);
}

void		get_null(int fd)
{
	uint8_t	b[4];
	int		i;

	if ((read(fd, b, 4)) < 4)
		error(10);
	i = 0;
	while (i < 4)
		if (b[i++] != 0)
			error(11);
}

t_header	*get_file(char *str)
{
	int			fd;
	uint8_t		b[4];
	t_header	*header;

	if (!(header = (t_header *)malloc(sizeof(t_header))))
		error(0);
	if ((fd = open(str, O_RDONLY)) < 2)
		error(6);
	if ((header->magic = get_int32(fd)) != COREWAR_EXEC_MAGIC)
		error(8);
	if (read(fd, header->prog_name, PROG_NAME_LENGTH) < PROG_NAME_LENGTH)
		error(9);
	get_null(fd);
	if ((header->prog_size = get_int32(fd)) > CHAMP_MAX_SIZE)
		error(12);
	if (read(fd, header->comment, COMMENT_LENGTH) < COMMENT_LENGTH)
		error(13);
	get_null(fd);
	if (!(header->code = (unsigned char *)malloc(header->prog_size)))
		error(0);
	if (read(fd, header->code, header->prog_size) != header->prog_size)
		error(14);
	if (read(fd, b, 4) != 0)
		error(14);
	return (header);
}
