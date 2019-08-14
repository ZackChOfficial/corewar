/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:38:46 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:13:59 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	print_won(t_sdl *data)
{
	SDL_Surface	*tit;
	SDL_Texture	*titl;
	SDL_Rect	titu;
	TTF_Font	*ok;

	ok = TTF_OpenFont("font/dig.ttf", 200);
	SDL_QueryTexture(data->out[1599], NULL, NULL, &titu.w, &titu.h);
	titu.x = (WIDTH - titu.w) / 2;
	titu.y = (HEIGHT - titu.h) / 2;
	SDL_RenderCopy(data->renderer, data->out[1599], NULL, &titu);
	tit = TTF_RenderText_Solid(ok, "WON", data->white);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1450;
	titu.y = 600;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	show_winner(t_sdl *data, t_vm *vm)
{
	SDL_Surface	*tit;
	SDL_Texture	*titl;
	SDL_Rect	titu;
	TTF_Font	*ok;

	ok = TTF_OpenFont("font/dig.ttf", 200);
	tit = TTF_RenderText_Solid(ok, vm->winner->data->prog_name,
data->pls[vm->winner->id * -1 - 1]);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 180;
	titu.y = 260;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	SDL_RenderPresent(data->renderer);
}

void	display_winner(t_sdl *data, t_vm *vm)
{
	int sag;

	sag = 1;
	Mix_HaltMusic();
	Mix_PlayMusic(data->wnr, -1);
	while (1)
	{
		exit_routine(data);
		if (sag == 1)
		{
			print_won(data);
			show_winner(data, vm);
			sag = 0;
		}
	}
}
