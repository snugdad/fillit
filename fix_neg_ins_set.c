/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_neg_ins_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:39:24 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:40:12 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void fix_neg_ins_set(void)
{
	int i;
	int j;
	int increment_x;
	int increment_y;

	i = -1;
	while(++i < inputed_minos)
	{
		increment_x = 0;
		increment_y = 0;
		j = -1;
		while(++j < 4)
		{
			if(g_mino[i]->ins_set[j][0] < 0 && increment_x > g_mino[i]->ins_set[j][0])
				increment_x = g_mino[i]->ins_set[j][0];
			if(g_mino[i]->ins_set[j][1] < 0 && increment_y > g_mino[i]->ins_set[j][1])
				increment_y = g_mino[i]->ins_set[j][1];
		}
		j = -1;
		while(++j < 4)
		{
			g_mino[i]->ins_set[j][0] += (increment_x * -1);
			g_mino[i]->ins_set[j][1] += (increment_y * -1);
		}
	}
}
