/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:03:24 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/11 18:27:01 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_input_f(char *file_name)
{
	int		n;
	char	*buf;
	int		fd;

	if (!file_name)
		throw_err(0);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFSIZE + 1))))
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		throw_err(0);
	n = read(fd, buf, BUFSIZE);
	buf[n] = '\0';
	if (buf[n - 1] != '\n')
		throw_err(0);
	if (n < 20)
		throw_err(0);
	return (buf);
}
