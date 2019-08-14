/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:58:39 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/07/31 19:44:34 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include "../../include/SDL2/SDL.h"
# include "../../include/SDL2/SDL_ttf.h"
# include "../../include/SDL2/SDL_mixer.h"
# define WIDTH 2100
# define HEIGHT 1200

typedef struct			s_coords
{
	char				c;
	int					i;
	int					id;
	int					state;
}						t_coords;

typedef struct			s_sdl
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Event			ev;
	SDL_Texture			**out;
	SDL_Rect			rectangle;
	TTF_Font			*btitle;
	TTF_Font			*stitle;
	TTF_Font			*vie;
	TTF_Font			*svie;
	Mix_Music			*bgm;
	Mix_Music			*wnr;
	Mix_Chunk			*coin;
	SDL_Color			black;
	SDL_Color			white;
	SDL_Color			cyan;
	SDL_Color			red;
	SDL_Color			pls[4];
	int					tag;
	int					delay;
	int					ttag;
}						t_sdl;

/*
** Visualization
*/

void					init_visu(t_sdl *data);
void					manage_events(t_sdl *data);
void					exit_routine(t_sdl *data);
void					init_screen(t_vm *vm, t_sdl *data);
void					check_colors(t_vm *vm, Mix_Chunk *coin);
void					print_everything(t_vm *vm, t_sdl *data);
void					vprint(t_vm *vm, t_sdl *data, SDL_Texture **out,
		int delay);
void					print_stats1(t_vm *vm, t_sdl *data);
void					print_stats2(t_vm *vm, t_sdl *data);
void					print_players_stats(t_vm *vm, t_sdl *data);
void					print_help(t_sdl *data);
void					draw_half_bite(t_coords pos, t_sdl *data);
void					draw_bgrnd(t_sdl *data, SDL_Texture **out);
SDL_Texture				**load_images(t_sdl *data, int j, int k);
char					fhex(unsigned char c);
char					shex(unsigned char c);
void					display_winner(t_sdl *data, t_vm *vm);
void					init_black(t_sdl *data);
void					init_red(t_sdl *data);
void					init_cyan(t_sdl *data);
void					init_white(t_sdl *data);
void					init_pls_cols(t_sdl *data);
int						min(int a, int b);
void					vbattle(t_vm *vm);
void					print_rem_ctc_bar(t_vm *vm, t_sdl *data);
void					print_clives(t_vm *vm, t_sdl *data);
void					print_rem_ctc_text(t_sdl *data);
void					print_numcycle(t_vm *vm, t_sdl *data);
void					print_numcursors(t_vm *vm, t_sdl *data);
void					print_ctd(t_vm *vm, t_sdl *data);
void					print_players_stats(t_vm *vm, t_sdl *data);
void					print_esc(t_sdl *data);
void					print_speed3(t_sdl *data);
void					print_speed2(t_sdl *data);
void					print_speed1(t_sdl *data);
void					print_pause(t_sdl *data);
void					load_logos3(SDL_Texture **out, t_sdl *data);
void					load_logos1(SDL_Texture **out, t_sdl *data);
void					load_logos2(SDL_Texture **out, t_sdl *data);

#endif
