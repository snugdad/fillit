/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_out_bounds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:46:43 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:47:15 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int is_out_bounds(int min_square_size, int mino_id, int pos[2])
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (g_mino[mino_id]->ins_set[i][0] + pos[0] >= min_square_size ||
				g_mino[mino_id]->ins_set[i][1] + pos[1] >= min_square_size)
			return (1);
	}
	return (0);
}
