/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:53:48 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/07 20:24:01 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_out_bounds(int min_square_size, int mino_id, int pos[2])
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (g_mino[mino_id]->ins_set[i][0] + pos[0] >= min_square_size ||
			g_mino[mino_id]->ins_set[i][1] + pos[1] >= min_square_size)
			return (1);
	}
	return (0);
}

int		get_most_left(int a, int b)
{
	return (a < 0 && b > a);
}

void	fix_neg_ins_set(void)
{
	int		i;
	int		j;
	int		increment_x;
	int		increment_y;

	i = -1;
	while (++i < g_inputed_minos)
	{
		increment_x = 0;
		increment_y = 0;
		j = -1;
		while (++j < 4)
		{
			if (get_most_left(g_mino[i]->ins_set[j][0], increment_x))
				increment_x = g_mino[i]->ins_set[j][0];
			if (get_most_left(g_mino[i]->ins_set[j][1], increment_y))
				increment_y = g_mino[i]->ins_set[j][1];
		}
		j = -1;
		while (++j < 4)
		{
			g_mino[i]->ins_set[j][0] += (increment_x * -1);
			g_mino[i]->ins_set[j][1] += (increment_y * -1);
		}
	}
}

void	fillit(int mino_sample_space[26][2], int min_square_size, int mino_id)
{
	int		pos[2];
	int		cp_sample_space[26][2];

	init_sample_space(cp_sample_space);
	copy_sample_space(mino_sample_space, cp_sample_space);
	if (mino_id == g_inputed_minos)
	{
		print_fillit(mino_sample_space, min_square_size, mino_id);
		exit(0);
	}
	pos[1] = -1;
	while (++pos[1] < min_square_size)
	{
		pos[0] = -1;
		while (++pos[0] < min_square_size)
		{
			if (place_mino(mino_sample_space, min_square_size, mino_id, pos))
				fillit(mino_sample_space, min_square_size, mino_id + 1);
			mino_sample_space = cp_sample_space;
		}
	}
	if (mino_id == 0)
		fillit(mino_sample_space, min_square_size + 1, mino_id);
}
