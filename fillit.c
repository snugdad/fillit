/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:53:48 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/06 16:42:25 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int inputed_minos;

t_mino *g_mino[26];

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

int is_out_bounds(int min_square_size, int mino_id, int pos[2])
{
    int i;

    i = -1; 
    while (++i < 4)
    {   
        if (g_mino[mino_id]->ins_set[i][0] + pos[0] >= min_square_size ||
                g_mino[mino_id]->ins_set[i][1] + pos[1] >= min_square_size)
            return (1);
    }   
    return (0);
}

void fix_neg_ins_set(void)
{
    int i;
    int j;
    int increment_x;
    int increment_y;

    i = -1; 
    while(++i < inputed_minos)
    {   
        increment_x = 0;
        increment_y = 0;
        j = -1; 
        while(++j < 4)
        {   
            if(g_mino[i]->ins_set[j][0] < 0 && increment_x > g_mino[i]->ins_set[j][0])
                increment_x = g_mino[i]->ins_set[j][0];
            if(g_mino[i]->ins_set[j][1] < 0 && increment_y > g_mino[i]->ins_set[j][1])
                increment_y = g_mino[i]->ins_set[j][1];
        }   
        j = -1; 
        while(++j < 4)
        {   
            g_mino[i]->ins_set[j][0] += (increment_x * -1);
            g_mino[i]->ins_set[j][1] += (increment_y * -1);
        }   
    }   
}

void init_sample_space(int mino_sample_space[26][2])
{
    int i;
    int j;

    i = -1; 
    while (++i < 26) 
    {   
        j = -1; 
        while (++j < 2)
            mino_sample_space[i][j] = 0;
    }   
}

void add_to_minos(int num_of_ts, int ***blocks)
{
    int i;
    int j;
    int k;
    int block_num;
    int first_x;
    int first_y;

    i = -1; 
    while (++i < num_of_ts)
    {   
        j = -1; 
        first_x = -1; 
        first_y = -1; 
        g_mino[i] = (t_mino *)ft_memalloc(sizeof(t_mino));
        block_num = 0;
        while (++j < 4)
        {   
            k = -1; 
            while (++k < 4)
            {   
                if (blocks[i][j][k] > 0)
                {   
                    first_x = (first_x == -1) ? k : first_x;
                    first_y = (first_y == -1) ? j : first_y;
                    // ft_putnbr(j - first_y);
                    g_mino[i]->ins_set[block_num][0] = k - first_x;
                    g_mino[i]->ins_set[block_num][1] = j - first_y;
                    block_num++;
                }   
            }   
        }   
    }   
    fix_neg_ins_set();
}

int place_mino(int m_ss[26][2], int min_square_size, int mino_id, int pos[2])
{   
    int i;

    i = -1; 
    ft_putnbr(mino_id);
    ft_putstr("Putting Coordinates:\n");
    ft_putnbr(pos[0]);
    ft_putstr(", ");
    ft_putnbr(pos[1]);
    ft_putchar('\n');
    if (is_out_bounds(min_square_size, mino_id, pos))
    {   
        ft_putstr("Strike OUT\n");
        return (0);
    }   
    while (++i < mino_id)
    {   
        if (m_ss[i][0] != pos[0] || m_ss[i][1] != pos[1])
        {   
            int j = -1; 
            while (++j < 4)
            {   
                int k = -1; 
                while (++k < 4)
                {   
                    if ((g_mino[mino_id]->ins_set[j][0] + pos[0] ==
                                g_mino[i]->ins_set[k][0] + m_ss[i][0]) &&
                            (g_mino[mino_id]->ins_set[j][1] + pos[1] ==
                             g_mino[i]->ins_set[k][1] + m_ss[i][1]))
                        return (0);
                }   
            }   
        }   
        else
            return (0);
    }   
    m_ss[mino_id][0] = pos[0];
    m_ss[mino_id][1] = pos[1];
    return (1);
}

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

void print_fillit(int m_ss[26][2], int min_square_size, int mino_id)
{
    int  i;  
    int  j;  
    char output[min_square_size][min_square_size];

    i = -1; 
    while (++i < min_square_size)
    {   
        j = -1; 
        while (++j < min_square_size)
            output[i][j] = '.';
    }   
    i = -1; 
    while (++i < mino_id)
    {   
        j = -1; 
        while (++j < 4)
            output[m_ss[i][1] + g_mino[i]->ins_set[j][1]]
                [m_ss[i][0] + g_mino[i]->ins_set[j][0]] = i + 65; 
    }   
    i = -1; 
    while (++i < min_square_size)
    {   
        j = -1; 
        while (++j < min_square_size)
            ft_putchar(output[i][j]);
        ft_putchar('\n');
    }   
}

void fillit(int mino_sample_space[26][2], int min_square_size, int mino_id)
{
	int pos[2];
	int cp_sample_space[26][2];
	init_sample_space(cp_sample_space);
	ft_putstr("Recursing: ");
	// ft_putnbr(mino_id);
	// ft_putstr(" Square_Size: ");
	// ft_putnbr(min_square_size);
	ft_putchar('\n');
	print_fillit(mino_sample_space, min_square_size, mino_id);
	copy_sample_space(mino_sample_space, cp_sample_space);
	if (mino_id == inputed_minos)
	{
		print_fillit(mino_sample_space, min_square_size, mino_id);
		exit(0);
	}
	pos[1] = -1;
	while (++pos[1] < min_square_size)
	{
		pos[0] = -1;
		while (++pos[0] < min_square_size)
		{
			if (place_mino(mino_sample_space, min_square_size, mino_id, pos))
				fillit(mino_sample_space, min_square_size, mino_id + 1);
			mino_sample_space = cp_sample_space;
		}
	}
	if (mino_id == 0)
		fillit(mino_sample_space, min_square_size + 1, mino_id);
}

void pars_char(char *input, int num_of_sq)
{
    int i;
    i = -1; 
    int valid_ch_count = 0;
    while (input[++i])
    {   
        if (input[i] == '#')
            valid_ch_count++;
        if (!(input[i] == '\n' || VALID_C(input[i])))
            exit(0);
    }   
    if(valid_ch_count < 4 || valid_ch_count % 4 != 0 || valid_ch_count / 4 != num_of_sq)
        exit(0);
    printf("number of tetrinos: %d\n", (int)num_of_sq);
    check_valid_mino(input, num_of_sq);
    inputed_minos = (int)num_of_sq;
    add_to_minos(inputed_minos, split_block(input, num_of_sq));
    int mino_ss[26][2];
    init_sample_space(mino_ss);
    fillit(mino_ss, 4, 0); 
}
