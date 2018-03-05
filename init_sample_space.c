/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sample_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:45:49 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:46:24 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void init_sample_space(int mino_sample_space[26][2])
{
	int i;
	int j;

	i = -1;
	while (++i < 26)
	{
		j = -1;
		while (++j < 2)
			mino_sample_space[i][j] = 0;
	}
}
