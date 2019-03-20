/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:43:52 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:39:05 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_strwidth(t_format *form, char **str, int count)
{
	*str = (char*)malloc(count);
	if (form->zero && !form->minus)
		ft_memset(*str, '0', count);
	else
		ft_memset(*str, ' ', count);
}

size_t		f_c(t_format *form, va_list *ap, char **buf)
{
	int		c;

	c = form->type == C ? va_arg(*ap, int) : '%';
	if (form->w_val > 1)
	{
		get_strwidth(form, buf, form->w_val);
		if (form->minus)
			(*buf)[0] = (char)c;
		else
			(*buf)[form->w_val - 1] = (char)c;
	}
	else
		*buf = ft_memdup(&c, 1);
	return (form->w_val > 1 ? form->w_val : 1);
}
