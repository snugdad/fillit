/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:34:03 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/07 20:19:45 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		***split_block(char *input, int num_of_trmno)
{
	int		***block_arr;
	int		tb_num;

	tb_num = 0;
	block_arr = (int ***)malloc(sizeof(int **) * (num_of_trmno));
	while (*input)
	{
		block_arr[tb_num] = tabdup_int(input, 20, tb_num);
		tb_num++;
		input += 21;
	}
	return (block_arr);
}
