/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:08:32 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:13:44 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		compare_block(size_t pos, size_t sq_size, size_t num_of_sq)
{
	if (pos < 20 || (pos - num_of_sq) % 20 != 0)
		return (1);
	else if ((pos - num_of_sq) % sq_size != 0)
	{   
		printf("no good in compare\n");
		return (0);
	}   
	else
		return (1);
}
