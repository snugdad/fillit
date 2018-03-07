# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 20:09:58 by egoodale          #+#    #+#              #
#    Updated: 2018/03/06 17:00:31 by egoodale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
INCLUDES =  fillit.h
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDES)
SRCS = compare_block.c\
	   strlen_to_newline.c\
	   get_input_f.c\
	   tabdup_int.c\
	   check_connection.c\
	   check_valid_mino.c\
	   split_block.c\
	   fillit.c\
	   pars_input.c\
	   main.c\
	   libft/*.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
		gcc $(CFLAGS) *.o -o $(NAME)

$(OBJS):
		gcc $(CFLAGS) -c $(SRCS)
clean: 
		rm -f *.o
re: clean all
