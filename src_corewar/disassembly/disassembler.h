/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <aalaoui-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:01:11 by aalaoui-          #+#    #+#             */
/*   Updated: 2019/07/31 15:59:33 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASSEMBLER_H
# define DISASSEMBLER_H
# include "../../src_asm/asm.h"
# include "./op_tab.h"

void				error(int i);
int					get_nb(char *nbr);
int					get_int32(int fd);
void				get_null(int fd);
t_header			*get_file(char *str);
char				*get_arg_type(char args_type);
int					read_four_bytes(unsigned char *str);
int					read_two_bytes(t_header *player, int index);
void				print_player_info(t_header *player);
int					print_arguments_treg(t_header *player, int index);
t_header			*get_t_header(int argc, char **argv);

#endif
