/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:19:58 by mray              #+#    #+#             */
/*   Updated: 2018/03/06 16:45:31 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>        //REMOVE THIS LATER
#include <stdlib.h>

#define BUFSIZE 4095
#define VALID_C(x) (x == '.' || x == '#' ? 1 : 0)

typedef struct	s_mino
{
				int ins_set[4][2];
}				t_mino;

int				compare_block(size_t pos, size_t sq_size, size_t num_of_sq);

size_t			strlen_to_newline(char *str);

int				**tabdup_int(char *src, int len, int ref);

int				check_connection(char *str);

void			check_valid_mino(char *input, int num_of_trmno);

int				***split_block(char *input, int num_of_trmno);

void			print_g_mino(void);

void			fix_neg_ins_set(void);

void			add_to_minos(int num_of_ts, int ***blocks);

void			copy_sample_space(int sample_space[26][2], int cp_sample_space[26][2]);

void			init_sample_space(int mino_sample_space[26][2]);

int				is_out_bounds(int min_square_size, int mino_id, int pos[2]);

int				place_mino(int m_ss[26][2], int min_square_size, int mino_id, int pos[2]);

void			print_fillit(int m_ss[26][2], int min_square_size, int mino_id);

void			fillit(int mino_sample_space[26][2], int min_square_size, int mino_id);

void			pars_char(char *input, int num_of_sq);

void			pars_input(char *input);

char			*get_input_f(char *file_name);

#endif























