/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:58:41 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/07 20:33:18 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	pars_char(char *input, int num_of_sq)
{
	int		i;
	int		mino_ss[26][2];
	int		valid_ch_count;

	valid_ch_count = 0;
	i = -1;
	while (input[++i])
	{
		if (input[i] == '#')
			valid_ch_count++;
		if (!(input[i] == '\n' || VALID_C(input[i])))
			throw_err(0);
	}
	if (valid_ch_count < 4 || valid_ch_count % 4 != 0 ||
	valid_ch_count / 4 != num_of_sq)
		throw_err(0);
	check_valid_mino(input, num_of_sq);
	g_inputed_minos = (int)num_of_sq;
	add_to_minos(g_inputed_minos, split_block(input, num_of_sq));
	init_sample_space(mino_ss);
	fillit(mino_ss, 2, 0);
}
