/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:52:11 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/11 03:07:55 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		try_put_piece(t_filler *fill, int i, int j, int *current_weight)
{
	int		k;
	int		l;
	int		f;

	k = -1;
	f = 0;
	(*current_weight) = 0;
	while (++k < fill->row_piece)
	{
		if (k + i > fill->row_map - 1)
			return (0);
		l = -1;
		while (++l < fill->column_piece)
		{
			if ((l + j > fill->column_map - 1)
				|| (fill->map[i + k][j + l].c == fill->enemy))
				return (0);
			(*current_weight) += fill->map[i + k][j + l].weight;
			if (fill->map[i + k][j + l].c == fill->player && fill->piece[k][l] == '*')
				f++;
		}
	}
	if (f == 1)
		return (1);
	return (0);
}

void	find_place(t_filler *fill, int i, int j)
{
	int		best_weight;
	int		current_weight;

	best_weight = 0;
	current_weight = 0;
	while (++i < fill->row_map)
	{
		j = -1;
		while (++j < fill->column_map)
		{
			if (fill->map[i][j].c == fill->enemy || fill->map[i][j].c == fill->enemy + 32)
				continue ;
			if (try_put_piece(fill, i, j, &current_weight))
			{
				if ((current_weight < best_weight && best_weight != 0) ||
					(current_weight > best_weight && best_weight == 0))
				{
					best_weight = current_weight;
					fill->res_coord[0] = i;
					fill->res_coord[1] = j;
				}
			}
		}
	}
}

void	put_piece(t_filler *fill)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	find_place(fill, i, j);
}
