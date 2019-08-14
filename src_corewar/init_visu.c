/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:23:26 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:15:43 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	init_colors(t_sdl *data)
{
	init_black(data);
	init_white(data);
	init_red(data);
	init_cyan(data);
	init_pls_cols(data);
}

void	init_visu(t_sdl *data)
{
	SDL_Rect	rectangle;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 ||
			(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0))
		error(15);
	data->window = SDL_CreateWindow("CoreWar", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	data->renderer = SDL_CreateRenderer(data->window, -1, 0);
	TTF_Init();
	data->out = load_images(data, 0, 0);
	SDL_QueryTexture(data->out[1599], NULL, NULL, &rectangle.w, &rectangle.h);
	rectangle.x = (WIDTH - rectangle.w) / 2;
	rectangle.y = (HEIGHT - rectangle.h) / 2;
	SDL_RenderCopy(data->renderer, data->out[1599], NULL, &rectangle);
	data->bgm = Mix_LoadMUS("mus/btl.ogg");
	data->wnr = Mix_LoadMUS("mus/win.ogg");
	data->coin = Mix_LoadWAV("mus/coin.wav");
	data->btitle = TTF_OpenFont("font/dig.ttf", 105);
	data->stitle = TTF_OpenFont("font/dig.ttf", 80);
	data->vie = TTF_OpenFont("font/dig2.ttf", 20);
	data->svie = TTF_OpenFont("font/dig2.ttf", 37);
	init_colors(data);
	data->tag = -1;
	data->ttag = -1;
	data->delay = 0;
}
