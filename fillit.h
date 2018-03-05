/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:19:58 by mray              #+#    #+#             */
/*   Updated: 2018/03/03 20:24:07 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int				g_inputed_minos;

int				compare_block(size_t pos, size_t sq_size, size_t num_of_sq);
