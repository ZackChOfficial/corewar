/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 12:24:27 by zchatoua          #+#    #+#             */
/*   Updated: 2019/07/31 14:02:11 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "./op.h"
# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# define DUMP 0
# define DUMP64 1
# define VISU 2
# define FIRST_ARG 192
# define SECOND_ARG 48
# define THIRD_ARG 12

typedef struct			s_player
{
	t_header			*data;
	int					id;
	int					start;
	int					live;
	int					last_live;
	struct s_player		*next;
}						t_player;

typedef struct			s_process
{
	int					id;
	int					player_id;
	int					carry;
	int					color;
	unsigned char		opcode;
	int					last_live;
	int					cycle_remaining;
	int					current_position;
	int					step_over;
	char				args[3];
	unsigned int		registers[REG_NUMBER];
	struct s_process	*next;
}						t_process;

typedef struct			s_vm
{
	unsigned char		*arena;
	int					*colors;
	t_player			*winner;
	unsigned int		cycle;
	int					cycles_to_die;
	int					old_cycle;
	int					lives;
	int					checks;
	int					process;
	int					player_nb;
	int					old;
	int					flags[3];
	t_player			*players;
	t_process			*carriages;
	int					id;
}						t_vm;

typedef	struct			s_op
{
	char				*name;
	uint8_t				args_num;
	uint8_t				args[3];
	uint8_t				opcode;
	uint16_t			cycle_remaining;
	char				*description;
	uint8_t				have_args;
	uint8_t				dir_size;
	void				(*fun)(t_vm *, t_process *);
}						t_op;
typedef	struct			s_arg_value
{
	int					dir_size;
	int					value;
	int					error;
}						t_arg_value;

/*
** Errors
*/

int						error(int i);
void					check_exec_players(t_vm *vm);

/*
** extract Flags
*/

int						get_flag(char *arg, int pos, t_vm *vm);
int						check_flags(char *str);
int						parse_args(int argc, char **argv, t_vm *vm);

/*
** Initialization
*/

void					init(t_vm *vm);
void					init_arena(t_vm *vm);
void					init_game(t_vm *vm);

/*
** Get Informations (getter)
*/

int						get_nb(char *nbr);
int						get_int32(int fd);
void					get_null(int fd);
t_header				*get_file(char *str);
void					parser(int argc, char **argv, t_vm *vm);
int						get_t_dir(t_vm *vm,
		t_process *process, t_arg_value *adr);
void					free_vm(t_vm *vm);
void					copy_data(t_player *dest, t_player *src);
short					mod_adr(short c);
short					gettwo(t_vm *vm, int adr);
unsigned char			get_one(unsigned char *str);
int						getfour(t_vm *vm, int adr);
void					write_four(t_vm *vm, int adr, int val, t_process *ptr);
int						skip_args(int arg_type, int n, int dir_s);
int						mod_adr_int(int c);
void					printit(t_vm *vm, int n);
int						check_arg(t_process *ptr, unsigned char arg, int n);
void					get_value(t_vm *vm, t_process *process,
		t_arg_value *arg, int type);
void					get_lvalue(t_vm *vm, t_process *process,
		t_arg_value *adr, int type);
void					check(t_vm *vm);
void					battle(t_vm *vm);
void					print_startgame(t_vm *vm);
t_header				*get_h_header(int argc, char **argv);

void					ft_live(t_vm *vm, t_process *process);
void					ft_ld(t_vm *vm, t_process *process);
void					ft_st(t_vm *vm, t_process *process);
void					ft_add(t_vm *vm, t_process *process);
void					ft_sub(t_vm *vm, t_process *process);
void					ft_and(t_vm *vm, t_process *process);
void					ft_or(t_vm *vm, t_process *process);
void					ft_xor(t_vm *vm, t_process *process);
void					ft_zjmp(t_vm *vm, t_process *process);
void					ft_ldi(t_vm *vm, t_process *process);
void					ft_sti(t_vm *vm, t_process *process);
void					ft_fork(t_vm *vm, t_process *process);
void					ft_lld(t_vm *vm, t_process *process);
void					ft_lldi(t_vm *vm, t_process *process);
void					ft_lfork(t_vm *vm, t_process *process);
void					ft_aff(t_vm *vm, t_process *process);
void					execute_process(t_vm *vm, t_process *ptr);
void					exec_loop(t_vm *vm);
void					add_players(t_vm *vm);
void					usage(void);
void					add_player(t_player **head, t_header *header, int *id);

static	t_op			g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, ft_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, ft_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, ft_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, ft_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, ft_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, ft_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, ft_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, ft_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, ft_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, ft_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, ft_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, ft_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, ft_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, ft_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, ft_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, ft_aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, NULL}
};

#endif
