/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_routines1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:11:41 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:07:46 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

int		min(int a, int b)
{
	return (a > b ? b : a);
}

void	print_clives(t_vm *vm, t_sdl *data)
{
	SDL_Surface	*tit;
	SDL_Texture	*titl;
	SDL_Rect	titu;
	char		*str;

	str = ft_itoa(vm->lives);
	tit = TTF_RenderText_Solid(data->vie, "Lives", data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1645;
	titu.y = 400;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	tit = TTF_RenderText_Solid(data->vie, str,
vm->lives < 21 ? data->cyan : data->red);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1760;
	titu.y = 400;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	free(str);
}

void	print_rem_ctc_text2(t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = TTF_RenderText_Solid(data->vie, "to", data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1665;
	titu.y = 475;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	tit = TTF_RenderText_Solid(data->vie, "Check", data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1650;
	titu.y = 500;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	print_rem_ctc_text(t_sdl *data)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = TTF_RenderText_Solid(data->vie, "Cycles", data->cyan);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 1640;
	titu.y = 450;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	print_rem_ctc_text2(data);
}

void	print_rem_ctc_bar(t_vm *vm, t_sdl *data)
{
	SDL_Rect	titu;
	int			x;

	x = ((vm->cycles_to_die -
(vm->cycle - vm->old_cycle)) * 100) / vm->cycles_to_die;
	x -= x % 2;
	if (x > 0)
	{
		SDL_QueryTexture(data->out[1700 + x / 2], NULL, NULL, &titu.w, &titu.h);
		titu.x = 1760;
		titu.y = 475;
		SDL_RenderCopy(data->renderer, data->out[1700 + x / 2], NULL, &titu);
	}
}
