/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 22:37:39 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/22 22:41:25 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wstr_init(t_printf *e, wchar_t **tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], wchar_t *);
		return ;
	}
	*tmp = va_arg(e->ap[0], wchar_t *);
}

void	wchar_init(t_printf *e, wchar_t *tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], wchar_t);
		return ;
	}
	*tmp = va_arg(e->ap[0], wchar_t);
}
