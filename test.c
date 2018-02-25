/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 11:36:40 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/24 17:27:48 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 4095
#define VALID_C(x) (x == '.' || x == '#' ? 1 : 0)


int	ft_compare_block(size_t pos, size_t sq_size, size_t num_of_sq)
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



size_t	ft_strlen_to_newline(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void	pars_input(char *input)
{
	size_t i;
	size_t sq_size;
	size_t num_of_sq;

	i = -1;
	sq_size = 5;
	num_of_sq = 0;
	while (input[++i])
	{
		if (!VALID_C(input[i]) || (ft_compare_block(i, sq_size - 5, num_of_sq) == 0))
		{
			printf("INVALID TETRINO : %d\n", (int)num_of_sq + 1);
		//	throw_err(1)
			return ;
		}
		i += ft_strlen_to_newline(input + i);
		if (((i + 1) - num_of_sq)  / sq_size == 4)
		{
			i++;
			sq_size += 5;
			num_of_sq++;
		}
	}
	printf("i: %d, num of sq: %d, sq_size: %d\n", (int)i, (int)num_of_sq, (int)sq_size);
	if (!((i - num_of_sq) % (sq_size - 5)))
		printf("number of tetrinos: %d", (int)num_of_sq);
}



char	*get_input_f(char *file_name)
{
	int n;
	char *buf;
	int fd;

	if(!(buf = (char *)malloc(sizeof(char) * (BUFSIZE + 1))))
		return NULL;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{	
		write (2, "open err", 8);
		return (0);
	}

	while ((n = read(fd, buf, BUFSIZE)) > 0)
		buf[n] = '\0';

	if (n < 0)
		write (2, "read err", 8);
	return (buf);
}





int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *tetra_list;

		tetra_list = get_input_f(argv[1]);
		printf("%s", tetra_list);

		pars_input(tetra_list);
	}
}
