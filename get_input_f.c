/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:03:24 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 20:04:40 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *get_input_f(char *file_name)
{
	int   n;
	char *buf;
	int   fd;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFSIZE + 1))))
		return NULL;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		write(2, "open err", 8);
		return (0);
	}

	while ((n = read(fd, buf, BUFSIZE)) > 0)
		buf[n] = '\0';

	if (n < 0)
		write(2, "read err", 8);
	return (buf);
}
