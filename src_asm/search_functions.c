/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:12:19 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/31 15:12:50 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		coun_args(t_asm *assm, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != COMMENT_CHAR && str[i] != ';')
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != SEPARATOR_CHAR &&
		str[i + 1] && (str[i + 1] == '\t' || str[i + 1] == ' '))
			search_for_separator(assm, str + i + 1);
		i++;
	}
	return (0);
}

void	get_file_name(t_asm *assm, char *str)
{
	int		i;
	char	s[1];

	i = ft_strlen(str) - 1;
	if (read(assm->fd, s, 0) < 0)
		error_system(9, -1);
	while (i >= 0)
	{
		if (str[i] == '.')
			break ;
		i--;
	}
	if (i < 0)
		i = 0;
	if (ft_strcmp(str + i, ".s"))
		error_system(8, -1);
	assm->file_name = ft_strsub(str, 0, i);
}

int		check_data_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\"')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int		info_start(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	if (str[i] == '\0')
		return (0);
	return (i);
}

int		eliminate_whitespace(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}
