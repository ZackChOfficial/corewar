/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_routines2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:14:38 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:08:01 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	print_checks(t_vm *vm, t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;
	char		*str;

	str = ft_itoa(vm->checks);
	tit = TTF_RenderText_Solid(data->vie, "Checks", data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1640;
	titu.y = 550;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	tit = TTF_RenderText_Solid(data->vie, str, data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1760;
	titu.y = 550;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	free(str);
}

void	print_stats2(t_vm *vm, t_sdl *data)
{
	print_clives(vm, data);
	print_rem_ctc_text(data);
	print_rem_ctc_bar(vm, data);
	print_checks(vm, data);
}

void	print_numcycle(t_vm *vm, t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;
	char		*str;

	str = ft_itoa(vm->cycle);
	tit = TTF_RenderText_Solid(data->svie, "Cycle : ", data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1610;
	titu.y = 100;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	tit = TTF_RenderText_Solid(data->svie, str, data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1770;
	titu.y = 100;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	free(str);
}

void	print_numcursors(t_vm *vm, t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;
	char		*str;

	str = ft_itoa(vm->process);
	tit = TTF_RenderText_Solid(data->svie, "Cursors : ", data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1610;
	titu.y = 200;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	tit = TTF_RenderText_Solid(data->svie, str, data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1790;
	titu.y = 200;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	free(str);
}

void	print_ctd(t_vm *vm, t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;
	char		*str;

	str = ft_itoa(vm->cycles_to_die);
	tit = TTF_RenderText_Solid(data->svie, "Cycles To Die : ", data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1610;
	titu.y = 300;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	tit = TTF_RenderText_Solid(data->svie, str, data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1910;
	titu.y = 300;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	free(str);
}
