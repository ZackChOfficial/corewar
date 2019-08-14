/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:05:28 by zchatoua          #+#    #+#             */
/*   Updated: 2019/05/18 17:18:26 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		line_reader(char **line, char *buf)
{
	char *newl;
	char *temp;
	char *temp2;

	newl = NULL;
	temp = NULL;
	if ((newl = ft_strchr(buf, '\n')))
	{
		temp = ft_strsub(buf, 0, ft_strlen(buf) - ft_strlen(newl));
		temp2 = *line;
		*line = ft_strjoin(temp2, temp);
		free(temp2);
		free(temp);
		buf = ft_strcpy(buf, newl + 1);
		return (1);
	}
	temp2 = *line;
	*line = ft_strjoin(temp2, buf);
	free(temp2);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char buf[2000][BUFF_SIZE + 1];

	ret = 0;
	if (fd < 0 || !(line) || BUFF_SIZE < 1)
		return (-1);
	*line = ft_strnew(0);
	if (buf[fd][0] && line_reader(line, buf[fd]))
		return (1);
	while ((ret = read(fd, buf[fd], BUFF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		buf[fd][ret] = '\0';
		if (line_reader(line, buf[fd]))
			return (1);
	}
	if (*line[0] != '\0')
	{
		ft_memset(buf[fd], 0, 1);
		return (1);
	}
	else
		free(*line);
	return (0);
}
