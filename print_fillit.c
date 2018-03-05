/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:52:35 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:53:01 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_fillit(int m_ss[26][2], int min_square_size, int mino_id)
{
	int  i;
	int  j;
	char output[min_square_size][min_square_size];

	i = -1;
	while (++i < min_square_size)
	{
		j = -1;
		while (++j < min_square_size)
			output[i][j] = '.';
	}
	i = -1;
	while (++i < mino_id)
	{
		j = -1;
		while (++j < 4)
			output[m_ss[i][1] + g_mino[i]->ins_set[j][1]]
				[m_ss[i][0] + g_mino[i]->ins_set[j][0]] = i + 65;
	}
	i = -1;
	while (++i < min_square_size)
	{
		j = -1;
		while (++j < min_square_size)
			ft_putchar(output[i][j]);
		ft_putchar('\n');
	}
}
