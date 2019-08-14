/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:18:55 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:07:21 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	print_players_hearts(t_sdl *data, t_player *pl)
{
	SDL_Rect rectangle;

	SDL_QueryTexture(data->out[1600 + pl->id * -1 - 1],
	NULL, NULL, &rectangle.w, &rectangle.h);
	rectangle.x = 50 + (pl->id * -1 - 1) * 430;
	rectangle.y = 42;
	SDL_RenderCopy(data->renderer, data->out[1600 + pl->id * -1 - 1],
	NULL, &rectangle);
	SDL_QueryTexture(data->out[1605 + pl->id * -1 - 1],
	NULL, NULL, &rectangle.w, &rectangle.h);
	rectangle.x = 50 + (pl->id * -1 - 1) * 430;
	rectangle.y = 60;
	SDL_RenderCopy(data->renderer, data->out[1605 + pl->id * -1 - 1],
	NULL, &rectangle);
}

void	print_players_name(t_sdl *data, t_player *pl)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;

	tit = TTF_RenderText_Solid(data->vie, pl->data->prog_name,
data->pls[pl->id * -1 - 1]);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 80 + (pl->id * -1 - 1) * 430 + 35;
	titu.y = 19;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
}

void	print_players_live(t_sdl *data, t_player *pl)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;
	char		*str;

	str = ft_itoa(pl->live);
	tit = TTF_RenderText_Solid(data->vie, ft_itoa(pl->live),
data->pls[pl->id * -1 - 1]);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 50 + (pl->id * -1 - 1) * 430 + 35;
	titu.y = 42;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	free(str);
}

void	print_players_llive(t_sdl *data, t_player *pl)
{
	SDL_Surface *tit;
	SDL_Texture *titl;
	SDL_Rect	titu;
	char		*str;

	str = ft_itoa(pl->last_live);
	tit = TTF_RenderText_Solid(data->vie, str,
data->pls[pl->id * -1 - 1]);
	titl = SDL_CreateTextureFromSurface(data->renderer, tit);
	SDL_FreeSurface(tit);
	titu.x = 50 + (pl->id * -1 - 1) * 430 + 35;
	titu.y = 63;
	SDL_QueryTexture(titl, NULL, NULL, &titu.w, &titu.h);
	SDL_RenderCopy(data->renderer, titl, NULL, &titu);
	SDL_DestroyTexture(titl);
	free(str);
}

void	print_players_stats(t_vm *vm, t_sdl *data)
{
	t_player *pl;

	pl = vm->players;
	while (pl)
	{
		print_players_hearts(data, pl);
		print_players_name(data, pl);
		print_players_live(data, pl);
		print_players_llive(data, pl);
		pl = pl->next;
	}
}
