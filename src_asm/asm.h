/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:43:09 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/31 16:24:06 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <fcntl.h>
# include "../libft/libft.h"
# include "./op_tab.h"

# define TRUE 1
# define FALSE 0

typedef struct				s_asm
{
	int						fd;
	char					*file_name;
	int						exec_code_found:1;
	int						size;
	t_op					tab[17];
	char					*name;
	char					*comment;
	char					*line;
	int						print_index;
	int						empty_label;
	int						error_index;
	struct s_instruction	*instruction;
}							t_asm;

typedef struct				s_instruction
{
	int						read_index;
	int						size;
	char					*label;
	char					*action;
	char					*arg[3];
	char					*arg_type;
	int						oneline : 1;
	int						index;
	int						nb_args;
	int						nb_args_filled;
	unsigned char			code;
	struct s_instruction	*next;
}							t_instruction;

int							parsing_line_check(char *line);
int							next_line_data(char **read, t_asm *assm, int i,
int k);
void						champion_info_parser(t_asm *assm);
void						get_label_name(t_asm *assembler,
t_instruction *instruction);
void						check_action(t_asm *assm,
t_instruction *instruction);
int							get_action(t_asm *assembler,
t_instruction *instruction);
void						argument_fill(char *line,
t_instruction *instruction, int i, int j);
void						get_argument(t_asm *assembler,
t_instruction *instruction);
void						get_all_arguments(t_asm *assembler,
t_instruction *instruction);
int							line_lexer(t_asm *assembler, int fd);
void						check_instruction(t_asm *assm);
int							label_address(t_asm *assm, char *label, int index);
int							arg_type_coding(t_asm *assm,
t_instruction *instruction,
int fd);
int							file_output(t_asm *assm);
int							endian_invert_int(int number);
short						endian_invert_short(short number);
void						error_system(int error, int line);
void						line_pre_parsing(t_asm *assm, char *line);
void						output_manager(t_asm *assm);
void						free_function(t_asm *assm);
int							free_all_function(t_asm *assm,
t_instruction *instrcution);
int							check_register(char *reg);
int							eliminate_whitespace(char *str);
int							check_empy_label(char *line);
int							check_dir_ind(char *arg);
void						print_dir_ind(int size_value, int value, int fd);
void						arguments_coding(t_asm *assm,
t_instruction *instruction, int fd);
void						output_name(t_asm *assm, int fd);
void						output_comment(t_asm *assm, int fd);
void						prog_info_validation(t_asm *assm);
int							info_start(char *str);
int							check_data_spaces(char *str);
void						get_file_name(t_asm *assm, char *str);
int							coun_args(t_asm *assm, char *str);
void						search_for_separator(t_asm *assm, char *str);
int							number_of_separators(t_asm *assembler,
t_instruction *instruction);
#endif
