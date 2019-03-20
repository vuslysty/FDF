/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:53:59 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 16:54:26 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cast_signed(long long int *n, va_list *ap, t_format *f)
{
	*n = va_arg(*ap, long long int);
	if (f->size)
	{
		if (f->s_val == 0)
			*n = (char)*n;
		else if (f->s_val == 1)
			*n = (short int)*n;
		else if (f->s_val == 3)
			*n = (long int)*n;
		else if (f->s_val == 4 || f->s_val == 5 || f->s_val == 6)
			*n = (int)*n;
	}
	else
		*n = (int)*n;
}
