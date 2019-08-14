/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:12:19 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/30 14:09:27 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		parsing_line_check(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ';' || line[i] == COMMENT_CHAR)
			return (1);
		if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	get_player_comment(t_asm *assm, char *read, int index)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	if (assm->comment)
		error_system(0, -1);
	else
	{
		i = ft_search(read, '\"');
		if (i < 0 || check_data_spaces(read + index + 8))
			error_system(0, -1);
		j = ft_search(read + i + 1, '\"');
		if (j < 0)
			j = next_line_data(&read, assm, i, k);
		assm->comment = ft_strsub(read, i + 1, j);
		if (!parsing_line_check(read + i + j + 2))
			error_system(0, -1);
		free(read);
	}
}

void	get_player_name(t_asm *assm, char *read, int index)
{
	int i;
	int j;
	int k;

	k = 0;
	if (assm->name)
		error_system(0, -1);
	else
	{
		i = ft_search(read, '\"');
		if (i < 0 || check_data_spaces(read + index + 5))
			error_system(0, -1);
		j = ft_search(read + i + 1, '\"');
		if (j < 0)
			j = next_line_data(&read, assm, i, k);
		if (!(assm->name = ft_strnew(j + 1)))
			exit(0);
		assm->name = ft_strncpy(assm->name, read + i + 1, j);
		if (!parsing_line_check(read + i + j + 2))
			error_system(0, -1);
		free(read);
	}
}

void	prog_info_validation(t_asm *assm)
{
	int i;

	i = 0;
	if (ft_strlen(assm->name) > PROG_NAME_LENGTH ||
ft_strlen(assm->comment) > COMMENT_LENGTH ||
assm->size > CHAMP_MAX_SIZE)
		error_system(0, -1);
}

void	champion_info_parser(t_asm *assm)
{
	char	*read;
	int		index;

	assm->error_index = 1;
	while (!assm->name || !assm->comment)
	{
		index = 0;
		if (!get_next_line(assm->fd, &read))
			error_system(0, -1);
		assm->error_index++;
		if (!parsing_line_check(read))
			index = info_start(read);
		if (ft_strnstr(read + index, NAME_CMD_STRING, 5))
			get_player_name(assm, read, index);
		else if (ft_strnstr(read + index, COMMENT_CMD_STRING, 8))
			get_player_comment(assm, read, index);
		else
		{
			if (!parsing_line_check(read))
				error_system(0, -1);
			free(read);
		}
	}
}
