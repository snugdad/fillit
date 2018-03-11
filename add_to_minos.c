/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_minos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:56:42 by mray              #+#    #+#             */
/*   Updated: 2018/03/07 20:34:40 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_to_minos_2(int para[6], int ***blocks)
{
	while (++para[1] < 4)
	{
		para[2] = -1;
		while (++para[2] < 4)
		{
			if (blocks[para[0]][para[1]][para[2]] > 0)
			{
				para[3] = (para[3] == -1) ? para[2] : para[3];
				para[4] = (para[4] == -1) ? para[1] : para[4];
				g_mino[para[0]]->ins_set[para[5]][0] = para[2] - para[3];
				g_mino[para[0]]->ins_set[para[5]][1] = para[1] - para[4];
				para[5]++;
			}
		}
	}
}

void	add_to_minos(int num_of_ts, int ***blocks)
{
	int		para[6];

	para[0] = -1;
	while (++para[0] < num_of_ts)
	{
		para[1] = -1;
		para[3] = -1;
		para[4] = -1;
		g_mino[para[0]] = (t_mino *)ft_memalloc(sizeof(t_mino));
		para[5] = 0;
		add_to_minos_2(para, blocks);
	}
	fix_neg_ins_set();
}
