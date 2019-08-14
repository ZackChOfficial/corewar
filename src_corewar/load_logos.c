/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_logos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:23:16 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:06:25 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	load_logos1(SDL_Texture **out, t_sdl *data)
{
	SDL_Surface *image;
	SDL_Texture *texture;

	image = SDL_LoadBMP("img/c1.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	SDL_FreeSurface(image);
	out[1600] = texture;
	image = SDL_LoadBMP("img/c2.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	SDL_FreeSurface(image);
	out[1601] = texture;
	image = SDL_LoadBMP("img/pp.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	out[1589] = texture;
	SDL_FreeSurface(image);
	image = SDL_LoadBMP("img/c3.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	out[1602] = texture;
	SDL_FreeSurface(image);
	image = SDL_LoadBMP("img/c4.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	out[1603] = texture;
	SDL_FreeSurface(image);
}

void	load_logos3(SDL_Texture **out, t_sdl *data)
{
	SDL_Surface *image;
	SDL_Texture *texture;

	image = SDL_LoadBMP("img/l1.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	out[1605] = texture;
	SDL_FreeSurface(image);
	image = SDL_LoadBMP("img/l2.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	out[1606] = texture;
	SDL_FreeSurface(image);
	image = SDL_LoadBMP("img/l3.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	out[1607] = texture;
	SDL_FreeSurface(image);
	image = SDL_LoadBMP("img/l4.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	out[1608] = texture;
	SDL_FreeSurface(image);
}

void	load_logos2(SDL_Texture **out, t_sdl *data)
{
	SDL_Surface *image;
	SDL_Texture *texture;

	image = SDL_LoadBMP("img/mb.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	SDL_FreeSurface(image);
	out[1599] = texture;
	image = SDL_LoadBMP("img/bk.bmp");
	texture = SDL_CreateTextureFromSurface(data->renderer, image);
	SDL_FreeSurface(image);
	out[1598] = texture;
}
