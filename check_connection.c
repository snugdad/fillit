/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:32:15 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 19:33:37 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     check_connection(char *str)
{
    int block;
    int i;

    block = 0;
    i = 0;
    while (i < 20)
    {
        if (str[i] == '#')
        {
            if ((i + 1) < 20 && str[i + 1] == '#')
                block++;
            if ((i - 1) >= 0 && str[i - 1] == '#')
                block++;
            if ((i + 5) < 20 && str[i + 5] == '#')
                block++;
            if ((i - 5) >= 0 && str[i - 5] == '#')
                block++;
        }
        i++;
    }
    return (block == 6 || block == 8);
}
