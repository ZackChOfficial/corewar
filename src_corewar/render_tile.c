/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:24:23 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:16:04 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

char	fhex(unsigned char c)
{
	int tmp;

	tmp = c / 16;
	if (tmp >= 10)
		return ('a' + tmp - 10);
	else
		return ('0' + tmp);
}

char	shex(unsigned char c)
{
	int tmp;

	tmp = c % 16;
	if (tmp >= 10)
		return ('a' + tmp - 10);
	else
		return ('0' + tmp);
}

void	draw_bgrnd(t_sdl *data, SDL_Texture **out)
{
	SDL_Rect rectangle;

	SDL_RenderClear(data->renderer);
	SDL_QueryTexture(out[1599], NULL, NULL, &rectangle.w, &rectangle.h);
	rectangle.x = (WIDTH - rectangle.w) / 2;
	rectangle.y = (HEIGHT - rectangle.h) / 2;
	SDL_RenderCopy(data->renderer, out[1599], NULL, &rectangle);
	SDL_QueryTexture(out[1589], NULL, NULL, &rectangle.w, &rectangle.h);
	rectangle.x = 30;
	rectangle.y = 82;
	SDL_RenderCopy(data->renderer, out[1589], NULL, &rectangle);
	SDL_QueryTexture(out[1598], NULL, NULL, &rectangle.w, &rectangle.h);
	rectangle.x = 46;
	rectangle.y = 98;
	SDL_RenderCopy(data->renderer, out[1598], NULL, &rectangle);
}

void	draw_half_bite(t_coords pos, t_sdl *data)
{
	int			j;
	int			x;
	SDL_Rect	rectangle;

	j = pos.i / 128;
	x = (pos.c >= 'a' && pos.c <= 'f' ? pos.c - 'a' + 10 : pos.c - '0');
	SDL_QueryTexture(data->out[100 * x + 10 * pos.id + pos.state],
	NULL, NULL, &rectangle.w, &rectangle.h);
	rectangle.x = 50 + (pos.i % 128) * 10 + (pos.i % 128) / 2 * 4;
	rectangle.y = 100 + j * 13 + j * 4;
	SDL_RenderCopy(data->renderer,
data->out[100 * x + 10 * pos.id + pos.state], NULL, &rectangle);
}
