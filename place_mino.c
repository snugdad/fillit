/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:46:58 by mray              #+#    #+#             */
/*   Updated: 2018/03/08 17:47:08 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_mino_2(int para[3], int mino_id, int m_ss[26][2], int pos[2])
{
	while (++para[2] < 4)
	{
		if ((g_mino[mino_id]->ins_set[para[1]][0] + pos[0] ==
			g_mino[para[0]]->ins_set[para[2]][0] + m_ss[para[0]][0]) &&
			(g_mino[mino_id]->ins_set[para[1]][1] + pos[1] ==
			g_mino[para[0]]->ins_set[para[2]][1] + m_ss[para[0]][1]))
			return (0);
	}
	return (-1);
}

int		place_mino(int m_ss[26][2], int min_square_size,
		int mino_id, int pos[2])
{
	int		para[3];

	para[0] = -1;
	if (is_out_bounds(min_square_size, mino_id, pos))
		return (0);
	while (++para[0] < mino_id)
	{
		if (m_ss[para[0]][0] != pos[0] || m_ss[para[0]][1] != pos[1])
		{
			para[1] = -1;
			while (++para[1] < 4)
			{
				para[2] = -1;
				if (place_mino_2(para, mino_id, m_ss, pos) != -1)
					return (0);
			}
		}
		else
			return (0);
	}
	m_ss[mino_id][0] = pos[0];
	m_ss[mino_id][1] = pos[1];
	return (1);
}
