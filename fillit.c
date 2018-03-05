/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:53:48 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:54:46 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void fillit(int mino_sample_space[26][2], int min_square_size, int mino_id)
{
	int pos[2];
	int cp_sample_space[26][2];
	init_sample_space(cp_sample_space);
	ft_putstr("Recursing: ");
	// ft_putnbr(mino_id);
	// ft_putstr(" Square_Size: ");
	// ft_putnbr(min_square_size);
	ft_putchar('\n');
	print_fillit(mino_sample_space, min_square_size, mino_id);
	copy_sample_space(mino_sample_space, cp_sample_space);
	if (mino_id == inputed_minos)
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
