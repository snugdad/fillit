/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:11:36 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:15:09 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int **tabdup_int(char *src, int len, int ref)
{
	int **tab;
	int   i = -1; 
	int   j = 0;
	int   k = 0;

	tab = (int **)malloc(sizeof(int *) * 4);
	while (j < 4)
		tab[j++] = (int *)malloc(sizeof(int) * 4);
	j = 0;
	while (++i < len)
	{
		if (src[i] == '#')
			tab[j][k++] = ref + 1;
		else if (src[i] == '.')
			tab[j][k++] = 0;
		if (k > 3)
		{
			j++;
			k = 0;
		}
	}
	return (tab);
}
