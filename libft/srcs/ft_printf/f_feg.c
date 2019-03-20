/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_feg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:48:48 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 18:49:45 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cast_float(long double *n, va_list *ap, t_format *f)
{
	if (!f->size || (f->size && f->s_val != 4))
		*n = va_arg(*ap, double);
	else
		*n = va_arg(*ap, long double);
}

size_t		f_feg(t_format *f, va_list *ap, char **str)
{
	long double	n;
	size_t		len;

	if (!f->precision)
	{
		f->precision = 1;
		f->p_val = 6;
	}
	if (f->minus && f->zero)
		f->zero = 0;
	cast_float(&n, ap, f);
	len = get_format_number2(f, &n, str);
	return (len);
}
