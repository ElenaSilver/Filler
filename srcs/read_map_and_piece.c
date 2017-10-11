/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_and_piece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:52:11 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/11 03:03:47 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	mem_for_map(t_filler *fill)
{
	int		i;

	i = -1;
	if (!(fill->map = (t_cell**)malloc(sizeof(t_cell*) * (fill->row_map))))
		return ;
	while (++i < fill->row_map)
		if (!(fill->map[i] = (t_cell*)malloc(sizeof(t_cell) * (fill->column_map))))
			return ;
}

void	mem_for_piece(t_filler *fill)
{
	int		i;

	if (!(fill->piece = (char**)malloc(sizeof(char*) * (fill->row_piece + 1))))
		return ;
	fill->piece[fill->row_piece] = 0;
	i = -1;
	while (++i < fill->row_piece)
	{
		if (!(fill->piece[i] = (char*)malloc(sizeof(char) * (fill->column_piece + 1))))
			return ;
		fill->piece[i][fill->column_piece] = '\0';
	}
}

void	read_map(t_filler *fill, char **str)
{
	int		i;
	int		j;

	find_size(str, &fill->row_map, &fill->column_map);
	free(*str);
	mem_for_map(fill);
	ft_get_next_line(0, str);
	free(*str);
	i = 0;
	while (i < fill->row_map)
	{
		ft_get_next_line(0, str);
		find_crd(fill, (*str) + 4, i);
		j = -1;
		while (++j < fill->column_map)
		{
			fill->map[i][j].c = (*str)[j + 4];
			fill->map[i][j].weight = 0;
		}
		i++;
		free(*str);
	}
}

void	read_piece(t_filler *fill, char **str)
{
	int		i;

	find_size(str, &fill->row_piece, &fill->column_piece);
	free(*str);
	mem_for_piece(fill);
	i = 0;
	while (i < fill->row_piece)
	{
		ft_get_next_line(0, str);
		ft_strcpy(fill->piece[i], *str);
		free(*str);
		i++;
	}
}

void	read_map_and_piece(t_filler *fill, char **str)
{
	if (ft_get_next_line(0, str) > 0)
		(ft_strstr(*str, "Plateau")) ? read_map(fill, str) : 0;
	if (ft_get_next_line(0, str) > 0)
		(ft_strstr(*str, "Piece")) ? read_piece(fill, str) : 0;
}
