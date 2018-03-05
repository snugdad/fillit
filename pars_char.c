/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:58:41 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:59:16 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void pars_char(char *input, int num_of_sq)
{
	int i;
	i = -1;
	int valid_ch_count = 0;
	while (input[++i])
	{
		if (input[i] == '#')
			valid_ch_count++;
		if (!(input[i] == '\n' || VALID_C(input[i])))
			exit(0);
	}
	if(valid_ch_count < 4 || valid_ch_count % 4 != 0 || valid_ch_count / 4 != num_of_sq)
		exit(0);
	printf("number of tetrinos: %d\n", (int)num_of_sq);
	check_valid_mino(input, num_of_sq);
	inputed_minos = (int)num_of_sq;
	add_to_minos(inputed_minos, split_block(input, num_of_sq));
	int mino_ss[26][2];
	init_sample_space(mino_ss);
	fillit(mino_ss, 4, 0);
}
