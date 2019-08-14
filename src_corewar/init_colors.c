/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 00:40:10 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 14:04:30 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"
#include "./includes/visu.h"

void	init_black(t_sdl *data)
{
	data->black.r = 0;
	data->black.g = 0;
	data->black.b = 0;
	data->black.a = 0;
}

void	init_red(t_sdl *data)
{
	data->red.r = 255;
	data->red.g = 0;
	data->red.b = 0;
	data->red.a = 0;
}

void	init_cyan(t_sdl *data)
{
	data->cyan.r = 0;
	data->cyan.g = 213;
	data->cyan.b = 255;
	data->cyan.a = 0;
}

void	init_white(t_sdl *data)
{
	data->white.r = 255;
	data->white.g = 255;
	data->white.b = 255;
	data->white.a = 0;
}

void	init_pls_cols(t_sdl *data)
{
	data->pls[0].r = 0;
	data->pls[0].g = 255;
	data->pls[0].b = 0;
	data->pls[0].a = 0;
	data->pls[1].r = 255;
	data->pls[1].g = 18;
	data->pls[1].b = 80;
	data->pls[1].a = 0;
	data->pls[2].r = 255;
	data->pls[2].g = 255;
	data->pls[2].b = 0;
	data->pls[2].a = 0;
	data->pls[3].r = 0;
	data->pls[3].g = 255;
	data->pls[3].b = 255;
	data->pls[3].a = 0;
}
