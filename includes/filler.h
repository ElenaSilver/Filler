/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:37:08 by skapteli          #+#    #+#             */
/*   Updated: 2017/10/11 03:11:32 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"

typedef struct		s_cell
{
	char			c;
	int				weight;
}					t_cell;

typedef struct		s_filler
{
	char			player;
	char			enemy;
	t_cell			**map;
	int				row_map;
	int				column_map;
	char			**piece;
	int				row_piece;
	int				column_piece;
	int				o_coord[2];
	int				x_coord[2];
	int				res_coord[2];
}					t_filler;

void				find_player(t_filler *fill, char **str);
void				find_size(char **str, int *n, int *x);
void				read_map_and_piece(t_filler *fill, char **str);
void				find_crd(t_filler *fill, char *str, int i);
void				calc_weight(t_filler *fill);
void				put_piece(t_filler *fill);
#endif
