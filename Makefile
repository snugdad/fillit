# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 20:09:58 by egoodale          #+#    #+#              #
#    Updated: 2018/03/03 20:22:58 by egoodale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
INCLUDES = libft/libft.h fillit.h libft/*.c
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDES)
SRCS = compare_block.c\
	   strlen_to_newline.c\
	   tabdup_int.c\
	   check_connection.c\
	   check_valid_mino.c\
	   split_block.c\
	   print_g_mino.c\
	   fix_neg_ins_set.c\
	   add_to_minos.c\
	   copy_sample_space.c\
	   init_sample_space.c\
	   is_out_bounds.c\
	   place_mino.c\
	   print_fillit.c\
	   fillit.c\
	   pars_char.c\
	   pars_input.c\
	   main.c\

all:
		gcc $(CFLAGS) $(SRCS)
clean: 
		rm -f $(NAME)
re: clean all
