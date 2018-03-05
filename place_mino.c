/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:51:10 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:52:25 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int place_mino(int m_ss[26][2], int min_square_size, int mino_id, int pos[2])
{   
	int i;

	i = -1;
	ft_putnbr(mino_id);
	ft_putstr("Putting Coordinates:\n");
	ft_putnbr(pos[0]);
	ft_putstr(", ");
	ft_putnbr(pos[1]);
	ft_putchar('\n');
	if (is_out_bounds(min_square_size, mino_id, pos))
	{   
		ft_putstr("Strike OUT\n");
		return (0);
	}
	while (++i < mino_id)
	{   
		if (m_ss[i][0] != pos[0] || m_ss[i][1] != pos[1])
		{   
			int j = -1;
			while (++j < 4)
			{   
				int k = -1;
				while (++k < 4)
				{   
					if ((g_mino[mino_id]->ins_set[j][0] + pos[0] ==
								g_mino[i]->ins_set[k][0] + m_ss[i][0]) &&
							(g_mino[mino_id]->ins_set[j][1] + pos[1] ==
							 g_mino[i]->ins_set[k][1] + m_ss[i][1]))
						return (0);
				}
			}
		}
		else
			return (0);
	}
	m_ss[mino_id][0] = pos[0];
	m_ss[mino_id][1] = pos[1];
	return (1);
}
