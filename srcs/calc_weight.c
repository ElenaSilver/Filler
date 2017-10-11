/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_weight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:52:11 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/11 02:59:29 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_abs(int *a, int *b)
{
	return ((*a - *b > 0) ? (*a - *b) : -(*a - *b));
}

/*
**	Formula:
**	weight = |x(current) - x(enemy))| + |y(current) - y(enemy)|
*/

void	calc_weight_to_enemy(t_filler *fill, int crd_row, int crd_col)
{
	int		i;
	int		j;
	int		buf;

	i = -1;
	buf = 0;
	while (++i < fill->row_map)
	{
		j = -1;
		while (++j < fill->column_map)
		{
			if (fill->map[i][j].c == fill->enemy)
			{
				fill->map[i][j].weight = 0;
				continue ;
			}
			else
				buf = ft_abs(&j, &crd_col) + ft_abs(&i, &crd_row);
			if (fill->map[i][j].weight == 0)
				fill->map[i][j].weight = buf;
			else if (fill->map[i][j].weight > buf)
				fill->map[i][j].weight = buf;
		}
	}
}

int		find_another_enemy(t_filler *fill, int *crd_row, int *crd_col)
{
	int		i;
	int		j;

	j = *crd_col + 1;
	if (*crd_row > -1)
		i = *crd_row;
	(j >= fill->column_map) ? (i = i + 1) : 0;
	(j >= fill->column_map) ? (j = 0) : 0;
	while (i < fill->row_map)
	{
		while (j < fill->column_map)
		{
			if (fill->map[i][j].c == fill->enemy
				|| fill->map[i][j].c == fill->enemy + 32)
			{
				*crd_row = i;
				*crd_col = j;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

/*
**	calculate weight for every cell
*/

void	calc_weight(t_filler *fill)
{
	int		crd_row;
	int		crd_col;

	if (fill->player == 'X')
	{
		crd_row = fill->o_coord[0];
		crd_col = fill->o_coord[1];
	}
	else
	{
		crd_row = fill->x_coord[0];
		crd_col = fill->x_coord[1];
	}
	calc_weight_to_enemy(fill, crd_row, crd_col);
	while (find_another_enemy(fill, &crd_row, &crd_col))
		calc_weight_to_enemy(fill, crd_row, crd_col);
}
