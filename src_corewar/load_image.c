/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:33:51 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:06:08 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

char			*ft_concat(char c, int i, int j)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 14);
	str[0] = 'i';
	str[1] = 'm';
	str[2] = 'g';
	str[3] = '/';
	str[4] = c;
	str[5] = '-';
	str[6] = '0' + i;
	str[7] = '-';
	str[8] = '0' + j;
	str[9] = '.';
	str[10] = 'b';
	str[11] = 'm';
	str[12] = 'p';
	str[13] = 0;
	return (str);
}

char			*ft_progbar(char *ptr)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(ptr);
	str = (char*)malloc(sizeof(char) * (len + 9));
	str[0] = 'i';
	str[1] = 'm';
	str[2] = 'g';
	str[3] = '/';
	i = 4;
	while (i - 4 < len)
	{
		str[i] = ptr[i - 4];
		i++;
	}
	str[i] = '.';
	str[i + 1] = 'b';
	str[i + 2] = 'm';
	str[i + 3] = 'p';
	str[i + 4] = 0;
	return (str);
}

void			load_progbar(t_sdl *data, SDL_Texture **out)
{
	char		*str;
	SDL_Surface	*img;
	int			i;

	i = 2;
	while (i <= 100)
	{
		str = ft_progbar(ft_itoa(i));
		img = SDL_LoadBMP(str);
		out[1700 + i / 2] = SDL_CreateTextureFromSurface(data->renderer, img);
		free(str);
		SDL_FreeSurface(img);
		i += 2;
	}
}

void			loading_loop(SDL_Texture **out, t_sdl *data, int j, int k)
{
	char		*str;
	char		c;
	int			i;

	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 10)
		{
			k = 0;
			while (k < 4)
			{
				c = (i >= 10 ? 'a' + i - 10 : '0' + i);
				str = ft_concat(c, j, k);
				out[100 * i + j * 10 + k] =
SDL_CreateTextureFromSurface(data->renderer, SDL_LoadBMP(str));
				free(str);
				k++;
			}
			j++;
		}
		i++;
	}
}

SDL_Texture		**load_images(t_sdl *data, int j, int k)
{
	SDL_Texture **out;

	out = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * 1760);
	loading_loop(out, data, j, k);
	load_progbar(data, out);
	load_logos1(out, data);
	load_logos2(out, data);
	load_logos3(out, data);
	return (out);
}
