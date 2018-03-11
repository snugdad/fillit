# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 20:09:58 by egoodale          #+#    #+#              #
#    Updated: 2018/03/11 13:57:19 by egoodale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
INCLUDES =  fillit.h

LIBFT	= libft/libft.a
CFLAGS = -g -Wall -Werror -Wextra -I $(INCLUDES)
SRCS = compare_block.c\
	   pars_char.c\
	   strlen_to_newline.c\
	   get_input_f.c\
	   tabdup_int.c\
	   check_connection.c\
	   check_valid_mino.c\
	   split_block.c\
	   fillit.c\
	   pars_input.c\
	   main.c\
	   add_to_minos.c\
	   throwerr.c\
	   place_mino.c\
	   print_fillit.c\
	   sample_space_helpers.c\

OBJ	= $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		gcc -I $(INCLUDES) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): $(LIBFT)
		gcc $(CFLAGS) -I $(LIBFT) -c $(SRCS)

$(LIBFT):
		cd libft && make
clean:
		rm -f $(OBJ)
		cd libft && make clean

fclean: clean
		rm -f $(NAME)
		cd libft && make fclean

re: fclean all
