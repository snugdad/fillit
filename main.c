/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:04:54 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/03 20:05:14 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
