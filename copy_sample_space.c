/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_sample_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:44:37 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:45:29 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void copy_sample_space(int sample_space[26][2], int cp_sample_space[26][2])
{
	int i;
	int k;

	i = -1;
	while (++i < 26)
	{
		k = -1;
		while (++k < 2)
			cp_sample_space[i][k] = sample_space[i][k];
	}
}
