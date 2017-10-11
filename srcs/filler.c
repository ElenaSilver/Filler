/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:52:11 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/11 02:53:34 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	initialize(t_filler *fill)
{
	fill->map = NULL;
	fill->row_map = 0;
	fill->column_map = 0;
	fill->piece = NULL;
	fill->row_piece = 0;
	fill->column_piece = 0;
	fill->o_coord[1] = -1;
	fill->o_coord[0] = -1;
	fill->x_coord[1] = -1;
	fill->x_coord[0] = -1;
	fill->res_coord[1] = 0;
	fill->res_coord[0] = 0;
}

void	free_struct(t_filler *fill)
{
	int		i;

	i = -1;
	if (fill->map)
		while (++i < fill->row_map)
			free(fill->map[i]);
	free(fill->map);
	i = -1;
	if (fill->piece)
		while (++i < fill->row_piece)
			free(fill->piece[i]);
	free(fill->piece);
}

void	start_filler(t_filler *fill, char **str)
{
	while (1)
	{
		initialize(fill);
		read_map_and_piece(fill, str);
		calc_weight(fill);
		put_piece(fill);
		ft_printf("%d %d\n", fill->res_coord[0], fill->res_coord[1]);
		free_struct(fill);
	}
}

int		main(void)
{
	char	*str;
	t_filler	*fill;

	fill = (t_filler *)malloc(sizeof(t_filler));
	if (ft_get_next_line(0, &str) > 0)
		if (ft_strstr(str, "filler"))
			find_player(fill, &str);
	if (str)
		free(str);
	start_filler(fill, &str);
	free(fill);
	return (0);
}
