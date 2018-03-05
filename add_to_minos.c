/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_minos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:41:12 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:42:06 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void add_to_minos(int num_of_ts, int ***blocks)
{
    int i;
    int j;
    int k;
    int block_num;
    int first_x;
    int first_y;

    i = -1;
    while (++i < num_of_ts)
    {
        j = -1;
        first_x = -1;
        first_y = -1;
        g_mino[i] = (t_mino *)ft_memalloc(sizeof(t_mino));
        block_num = 0;
        while (++j < 4)
        {
            k = -1;
            while (++k < 4)
            {
                if (blocks[i][j][k] > 0)
                {
                    first_x = (first_x == -1) ? k : first_x;
                    first_y = (first_y == -1) ? j : first_y;
                    // ft_putnbr(j - first_y);
                    g_mino[i]->ins_set[block_num][0] = k - first_x;
                    g_mino[i]->ins_set[block_num][1] = j - first_y;
                    block_num++;
                }
            }
        }
    }
    fix_neg_ins_set();
}
