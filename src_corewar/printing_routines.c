/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_routines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:11:23 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:07:35 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	print_logo(t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = TTF_RenderText_Solid(data->vie, "By THE ARGYRASPIDES", data->pls[2]);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1840;
	titu.y = 1170;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	print_help(t_sdl *data)
{
	print_pause(data);
	print_speed1(data);
	print_speed2(data);
	print_speed3(data);
	print_esc(data);
	print_logo(data);
}

void	print_everything(t_vm *vm, t_sdl *data)
{
	vprint(vm, data, data->out, data->delay);
	print_stats1(vm, data);
	print_stats2(vm, data);
	print_players_stats(vm, data);
	print_help(data);
	SDL_RenderPresent(data->renderer);
}
