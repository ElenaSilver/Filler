/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:34:30 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/24 23:16:45 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	invalid_width(t_printf *e)
{
	while (e->flag.width-- > 1)
		e->ret += (e->flag.zero == 1 ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

static void	invalid_spec(t_printf *e, char c)
{
	if (e->flag.minus)
	{
		e->ret += write(e->fd, &c, 1);
		invalid_width(e);
	}
	else
	{
		invalid_width(e);
		e->ret += write(e->fd, &c, 1);
	}
	e->i++;
}

void		get_spec(const char *restrict format, t_printf *e)
{
	if (format[e->i] == '%')
		spec_percent(e);
	else if ((format[e->i] == 'd' || format[e->i] == 'i') && e->modifier != z)
		spec_int(e);
	else if (format[e->i] == 'u' || format[e->i] == 'U' || format[e->i] == 'D'
		|| ((format[e->i] == 'd' || format[e->i] == 'i') && e->modifier == z))
		spec_unsint(e, format[e->i]);
	else if ((format[e->i] == 'c' || format[e->i] == 's') && e->modifier != l)
		spec_char(e, format[e->i]);
	else if (format[e->i] == 'C' || format[e->i] == 'S')
		spec_char(e, format[e->i] + 32);
	else if (((format[e->i] == 'c' || format[e->i] == 's') && e->modifier == l)
			|| format[e->i] == 'C' || format[e->i] == 'S')
		spec_wchar(e, format[e->i]);
	else
		get_spec_more(format, e);
}

void		get_spec_more(const char *restrict format, t_printf *e)
{
	if (format[e->i] == 'o' || format[e->i] == 'b' || format[e->i] == 'x' ||
			format[e->i] == 'O' || format[e->i] == 'B' || format[e->i] == 'X')
		init_base(e, format[e->i]);
	else if (format[e->i] == 'n')
		spec_return(e);
	else if (format[e->i] == 'p')
		spec_ptr(e, format[e->i]);
	else if (format[e->i] != '\0')
		invalid_spec(e, format[e->i]);
}
