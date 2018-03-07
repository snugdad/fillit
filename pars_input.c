/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:00:47 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/06 16:44:36 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void pars_input(char *input)
{   
	size_t i;
	size_t sq_size;
	size_t num_of_sq;

	i = -1; 
	sq_size = 5;
	num_of_sq = 0;
	ft_putstr(input);
	while (input[++i])
	{   
		if (!VALID_C(input[i]) ||
				(compare_block(i, sq_size - 5, num_of_sq) == 0))
		{   
			printf("INVALID TETRINO : %d\n", (int)num_of_sq + 1);
			//  throw_err(1)
			return;
		}
		i += strlen_to_newline(input + i);
		if (((i + 1) - num_of_sq) / sq_size == 4)
		{
			i++;
			sq_size += 5;
			num_of_sq++;
		}
	}
	printf("i: %d, num of sq: %d, sq_size: %d\n", (int)i, (int)num_of_sq,
			(int)sq_size);
	if (!((i - num_of_sq) % (sq_size - 5)))
	{
		pars_char(input, (int)num_of_sq);
		/*printf("number of tetrinos: %d\n", (int)num_of_sq);
		  inputed_minos = (int)num_of_sq;
		  add_to_minos(inputed_minos, split_block(input, num_of_sq));
		  int mino_ss[26][2];
		  init_sample_space(mino_ss);
		  fillit(mino_ss, 4, 0);*/
	}
}

