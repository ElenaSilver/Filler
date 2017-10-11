/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_itoa_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:34:30 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/22 20:10:21 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_lenght(uintmax_t n, int base, int *len)
{
	int i;

	i = 1;
	while (n >= (unsigned)base)
	{
		n /= base;
		i++;
	}
	*len = i;
}

char		*ft_uintmax_itoa_base(uintmax_t val, int base)
{
	char			*res;
	char			bs[17];
	int				len;

	len = 1;
	ft_strcpy(bs, "0123456789ABCDEF");
	if (val == 0)
		return (ft_strdup("0"));
	ft_lenght(val, base, &len);
	res = (char*)malloc(sizeof(char) * len + 1);
	res[len--] = '\0';
	while (val >= (unsigned)base)
	{
		res[len--] = bs[val % base];
		val /= base;
	}
	res[len] = bs[val % base];
	return (res);
}
