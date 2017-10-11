/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_data_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:34:30 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/24 21:40:58 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uintmax_t_init(t_printf *e, uintmax_t *tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], uintmax_t);
		return ;
	}
	*tmp = va_arg(e->ap[0], uintmax_t);
}

void	long_long_init(t_printf *e, long long *tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], long long);
		return ;
	}
	*tmp = va_arg(e->ap[0], long long);
}

void	char_init(t_printf *e, char **tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], char *);
		return ;
	}
	*tmp = va_arg(e->ap[0], char *);
}

void	int_init(t_printf *e, int *tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], int);
		return ;
	}
	*tmp = va_arg(e->ap[0], int);
}
