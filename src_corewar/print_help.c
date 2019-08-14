/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:20:55 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:07:10 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	print_pause(t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = TTF_RenderText_Solid(data->vie, "run / pause      p", data->white);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1830;
	titu.y = 950;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	print_speed1(t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = TTF_RenderText_Solid(data->vie, "max speed        q", data->white);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1830;
	titu.y = 975;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	print_speed2(t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = TTF_RenderText_Solid(data->vie, "med speed        w", data->white);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1830;
	titu.y = 1000;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	print_speed3(t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = TTF_RenderText_Solid(data->vie, "min speed         e", data->white);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1830;
	titu.y = 1025;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	print_esc(t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit =
TTF_RenderText_Solid(data->vie, "exit                 esc", data->white);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1830;
	titu.y = 1050;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}
