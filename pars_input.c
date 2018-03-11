/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:00:47 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/11 14:17:14 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	pars_input(char *input)
{
	size_t	i;
	size_t	sq_size;
	size_t	num_of_sq;

	i = -1;
	sq_size = 5;
	num_of_sq = 0;
	while (input[++i])
	{
		if (!VALID_C(input[i]) ||
				(compare_block(i, sq_size - 5, num_of_sq) == 0))
			throw_err(0);
		i += strlen_to_newline(input + i);
		if (((i + 1) - num_of_sq) / sq_size == 4)
		{
			i++;
			sq_size += 5;
			num_of_sq++;
		}
	}
	if ((input[i - 1] != '\n') &&
	!(sq_size <= 5) && !(((i - num_of_sq) % (sq_size - 5))))
		pars_char(input, (int)num_of_sq);
	else
		throw_err(0);
}
