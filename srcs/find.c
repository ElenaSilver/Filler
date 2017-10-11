/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:52:11 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/11 03:10:57 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	Creat str with number
*/

char	*find_num(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	i = 0;
	while (!(ft_isdigit(str[i])))
		i++;
	j = i;
	while ((ft_isdigit(str[j])) && str[j])
		j++;
	if (!(ret = (char*)malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	k = 0;
	while (str[i] && i < j)
		ret[k++] = str[i++];
	ret[k] = '\0';
	return (ret);
}

/*
**	Find number of player: p1 or p2
*/

void	find_player(t_filler *fill, char **str)
{
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if (ft_isdigit((*str)[i]))
		{
			fill->player = ((*str)[i] == '1') ? 'O' : 'X';
			fill->enemy = ((*str)[i] == '1') ? 'X' : 'O';
			break ;
		}
		i++;
	}
}

/*
**	Find size: col - columns, row - rows
*/

void	find_size(char **str, int *row, int *col)
{
	char	*numstr;
	int		i;
	int		f;

	i = -1;
	f = 0;
	while ((*str)[++i])
	{
		if (ft_isdigit((*str)[i]) && f == 0)
		{
			numstr = find_num((*str) + i);
			*row = ft_atoi(numstr);
			i += ft_strlen(numstr);
			f = 1;
			continue ;
		}
		if (ft_isdigit((*str)[i]) && f == 1)
		{
			numstr = find_num((*str) + i);
			*col = ft_atoi(numstr);
			break ;
		}
	}
}

/*
**	Find coordinations for O and X
*/

void	find_crd(t_filler *fill, char *str, int i)
{
	int		j;

	j = -1;
	while (++j < fill->column_map)
	{
		if (fill->o_coord[1] == -1 && fill->o_coord[0] == -1)
		{
			if (str[j] == 'O' || str[j] == 'o')
			{
				fill->o_coord[0] = i;
				fill->o_coord[1] = j;
			}
		}
		if (fill->x_coord[1] == -1 && fill->x_coord[0] == -1)
		{
			if (str[j] == 'X' || str[j] == 'x')
			{
				fill->x_coord[0] = i;
				fill->x_coord[1] = j;
			}
		}
		if (fill->o_coord[1] > -1 && fill->o_coord[0] > -1 && fill->x_coord[1] > -1 && fill->x_coord[0] > 1)
			return ;
	}
}
