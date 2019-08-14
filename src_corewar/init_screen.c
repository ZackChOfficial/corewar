/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:41:58 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:14:52 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	draw_player_num(t_vm *vm, t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = NULL;
	if (vm->player_nb == 1)
		tit = TTF_RenderText_Solid(data->stitle, "1", data->white);
	else if (vm->player_nb == 2)
		tit = TTF_RenderText_Solid(data->stitle, "2", data->white);
	else if (vm->player_nb == 3)
		tit = TTF_RenderText_Solid(data->stitle, "3", data->white);
	else if (vm->player_nb == 4)
		tit = TTF_RenderText_Solid(data->stitle, "4", data->white);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1450;
	titu.y = 267;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	draw_player_names(t_vm *vm, t_sdl *data, int k, SDL_Point pp)
{
	t_player		*pl;
	TTF_Font		*title;
	SDL_Surface		*tit;
	SDL_Texture		*titl;
	SDL_Rect		titu;

	pl = vm->players;
	pp.x = 0;
	pp.y = 0;
	while (pl)
	{
		title = TTF_OpenFont("font/dig.ttf",
	min(1300 / (ft_strlen(pl->data->prog_name)), 1300 / 15));
		tit =
TTF_RenderText_Solid(title, pl->data->prog_name, data->pls[-1 * pl->id - 1]);
		titl = SDL_CreateTextureFromSurface(data->renderer, tit);
		SDL_FreeSurface(tit);
		titu.x = 1550 + 92 * k - ft_strlen(pl->data->prog_name);
		titu.y = 380;
		SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
		SDL_RenderCopyEx(data->renderer, titl, NULL,
&titu, 90, &pp, SDL_FLIP_NONE);
		pl = pl->next;
		k++;
	}
}

void	next_mssg(t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = TTF_RenderText_Solid(data->vie,
"press space to continue", data->white);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 883;
	titu.y = 1037;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	write_core_war(t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = TTF_RenderText_Solid(data->btitle, "Core War", data->black);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = WIDTH / 2 - 250;
	titu.y = 190;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	init_screen(t_vm *vm, t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;
	SDL_Point	pp;

	write_core_war(data);
	tit = TTF_RenderText_Solid(data->stitle,
(vm->player_nb == 1 ? "Player" : "Players"), data->white);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1518;
	titu.y = 267;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	pp.x = 0;
	pp.y = 0;
	draw_player_num(vm, data);
	draw_player_names(vm, data, 0, pp);
	next_mssg(data);
	SDL_RenderPresent(data->renderer);
}
