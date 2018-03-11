/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_space_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:50:02 by mray              #+#    #+#             */
/*   Updated: 2018/03/08 17:50:12 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_sample_space(int mino_sample_space[26][2])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 26)
	{
		j = -1;
		while (++j < 2)
			mino_sample_space[i][j] = 0;
	}
}

void	copy_sample_space(int sample_space[26][2], int cp_sample_space[26][2])
{
	int		i;
	int		k;

	i = -1;
	while (++i < 26)
	{
		k = -1;
		while (++k < 2)
			cp_sample_space[i][k] = sample_space[i][k];
	}
}
