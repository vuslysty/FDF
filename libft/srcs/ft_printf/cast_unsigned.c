/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:54:42 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/26 16:38:29 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cast_unsigned(unsigned long long int *n, va_list *ap, t_format *f)
{
	if (f->type == P)
	{
		f->sharp = 1;
		*n = (unsigned long long)(va_arg(*ap, void*));
	}
	else
		*n = va_arg(*ap, unsigned long long int);
	if (f->type != P)
	{
		if (f->size)
		{
			if (f->s_val == 0)
				*n = (unsigned char)*n;
			else if (f->s_val == 1)
				*n = (unsigned short int)*n;
			else if (f->s_val == 3)
				*n = (unsigned long int)*n;
			else if (f->s_val == 4 || f->s_val == 5 || f->s_val == 6)
				*n = (unsigned int)*n;
		}
		else
			*n = (unsigned int)*n;
	}
}
