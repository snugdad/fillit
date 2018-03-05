/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_g_mino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:38:20 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:38:49 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_g_mino()
{
	int i = -1;
	while (++i < inputed_minos)
	{
		int j = -1;
		while (++j < 4)
		{
			ft_putnbr(g_mino[i]->ins_set[j][0]);
			ft_putnbr(g_mino[i]->ins_set[j][1]);
		}
		ft_putchar('\n');
	}
}
