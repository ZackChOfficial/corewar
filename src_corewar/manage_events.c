/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:52:37 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:06:41 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	exit_routine(t_sdl *data)
{
	SDL_PollEvent(&(data->ev));
	if (data->ev.type == SDL_QUIT)
	{
		SDL_DestroyRenderer(data->renderer);
		SDL_DestroyWindow(data->window);
		SDL_Quit();
		exit(0);
	}
	else if (data->ev.type == SDL_KEYDOWN)
	{
		if (data->ev.key.keysym.sym == SDLK_ESCAPE)
		{
			SDL_DestroyRenderer(data->renderer);
			SDL_DestroyWindow(data->window);
			SDL_Quit();
			exit(0);
		}
	}
}

void	manage_events(t_sdl *data)
{
	if (!Mix_PlayingMusic())
	{
		if (data->tag == 1)
			Mix_PlayMusic(data->bgm, -1);
	}
	SDL_PollEvent(&(data->ev));
	if (data->ev.type == SDL_QUIT)
		exit(0);
	else if (data->ev.type == SDL_KEYDOWN)
	{
		if (data->ev.key.keysym.sym == SDLK_SPACE)
			data->tag = 1;
		if (data->ev.key.keysym.sym == SDLK_p)
			data->ttag *= -1;
		else if (data->ev.key.keysym.sym == SDLK_q)
			data->delay = 0;
		else if (data->ev.key.keysym.sym == SDLK_w)
			data->delay = 50000;
		else if (data->ev.key.keysym.sym == SDLK_e)
			data->delay = 800000;
		else if (data->ev.key.keysym.sym == SDLK_ESCAPE)
			exit(0);
	}
}
