# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 16:28:45 by mmaaouni          #+#    #+#              #
#    Updated: 2019/07/31 21:28:23 by aalaoui-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = corewar
NAME2 = asm
NAME3 = visu
NAME4 = dsm

FILES_SHARED = src_corewar/check.c src_corewar/error.c src_corewar/exec.c\
			   src_corewar/flags.c src_corewar/freeing.c src_corewar/get_value.c\
			   src_corewar/getter.c src_corewar/init.c src_corewar/module.c src_corewar/op_add.c\
			   src_corewar/op_aff.c src_corewar/op_and.c src_corewar/op_fork.c src_corewar/op_ld.c\
			   src_corewar/op_ldi.c src_corewar/op_live.c src_corewar/op_lld.c src_corewar/op_lldi.c\
			   src_corewar/op_or.c src_corewar/op_st.c src_corewar/op_sti.c src_corewar/op_sub.c\
			   src_corewar/op_xor.c src_corewar/op_zjmp.c src_corewar/parseit.c src_corewar/parser.c\
			   src_corewar/print.c src_corewar/utils.c
FILE_COREWAR = src_corewar/corewar.c
FILE_VISU    = src_corewar/check_colors.c src_corewar/display_winner.c src_corewar/init_colors.c src_corewar/init_screen.c\
			   src_corewar/init_visu.c src_corewar/load_image.c src_corewar/load_logos.c src_corewar/manage_events.c\
			   src_corewar/print_help.c src_corewar/print_stats.c src_corewar/printing_routines.c\
			   src_corewar/printing_routines1.c src_corewar/printing_routines2.c src_corewar/printing_routines3.c\
			   src_corewar/render_tile.c src_corewar/vbattle.c src_corewar/visu.c
FILE_DSM     = src_corewar/disassembly/disassembly.c src_corewar/disassembly/get_header.c \
			   src_corewar/disassembly/help_functions.c
FILES_ASM    = src_asm/asm.c src_asm/byte_code_encoder.c src_asm/byte_code_output.c src_asm/free_functions.c\
			   src_asm/help_functions.c src_asm/info_output.c src_asm/lexical_checking.c\
			   src_asm/lexing_functions_action.c src_asm/lexing_functions_label.c \
			   src_asm/lexing_functions.c src_asm/parsing_functions.c src_asm/search_functions.c\
			   src_asm/search_validation.c
OBJ_SHARED = $(FILES_SHARED:.c=.o)
OBJ_COREWAR = $(FILE_COREWAR:.c=.o)
OBJ_VISU = $(FILE_VISU:.c=.o)
OBJ_DSM = $(FILE_DSM:.c=.o)
OBJ_ASM = $(FILES_ASM:.c=.o)
LIB = libft/libft.a
DIR = libft

all: $(NAME1) $(NAME2) $(NAME3) $(NAME4)

$(NAME1):  $(LIB) $(OBJ_COREWAR) $(OBJ_SHARED)
	gcc -Wall -Wextra -Werror $(OBJ_COREWAR) $(LIB) $(OBJ_SHARED) -o $(NAME1)
$(NAME2): $(LIB) $(OBJ_ASM)
	gcc -Wall -Wextra -Werror $(LIB) $(OBJ_ASM) -o $(NAME2)
$(NAME3): $(LIB) $(OBJ_SHARED) $(OBJ_VISU)
	gcc -Wall -Wextra -Werror $(LIB) $(OBJ_SHARED) $(OBJ_VISU) -I include -Llib -lSDL2  -lSDL2_ttf -lSDL2_mixer -o $(NAME3)
$(NAME4): $(LIB) $(OBJ_SHARED) $(OBJ_DSM)
	gcc -Wall -Wextra -Werror $(LIB) $(OBJ_SHARED) $(OBJ_DSM) -o $(NAME4)
$(OBJ_SHARED): %.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@
$(OBJ_COREWAR): %.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@
$(OBJ_VISU): %.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@
$(OBJ_DSM): %.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@
$(OBJ_ASM): %.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@
$(LIB):
	make -C $(DIR)
clean:
	make -C $(DIR) clean
	rm -f $(OBJ_SHARED) $(OBJ_VISU) $(OBJ_COREWAR) $(OBJ_DSM) $(OBJ_ASM)
fclean: clean
	make -C $(DIR) fclean
	rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4)
re: fclean  $(NAME1) $(NAME2) $(NAME3) $(NAME4)

norminette:
	norminette $(FILES_SHARED) $(FILE_COREWAR) $(FILE_VISU) $(FILES_ASM) $(FILE_DSM) libft/*.c
