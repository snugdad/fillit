/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:30:22 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/07 20:29:07 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_valid_mino(char *input, int num_of_trmno)
{
	char	**block_arr;
	int		block_nb;
	int		i;

	block_arr = (char **)malloc(sizeof(char *) * (num_of_trmno + 1));
	block_arr[num_of_trmno] = 0;
	i = 0;
	block_nb = 0;
	while (input[i])
	{
		block_arr[block_nb] = ft_strndup(&input[i], 20);
		if (!(check_connection(block_arr[block_nb])))
			throw_err(0);
		i += 21;
	}
	return ;
}
