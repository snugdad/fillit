/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:34:03 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/06 16:39:15 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ***split_block(char *input, int num_of_trmno)
{
	int ***block_arr;
	int tb_num = 0;

	block_arr = (int ***)malloc(sizeof(int **) * (num_of_trmno));
	while (*input)
	{
		block_arr[tb_num] = tabdup_int(input, 20, tb_num);
		tb_num++;
		input += 21;
	}
	for (int i = 0; i < tb_num; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
				printf("%d", block_arr[i][j][k]);
			printf("\n");
		}
		printf("\n\n");
	}
	return (block_arr);
}
