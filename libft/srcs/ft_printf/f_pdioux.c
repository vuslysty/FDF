/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pdioux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:50:52 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 18:51:15 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	f_pdioux(t_format *f, va_list *ap, char **str)
{
	void	*n;
	size_t	len;

	n = malloc(16);
	if (f->minus && f->zero)
		f->zero = 0;
	if (f->type == P || (f->type >= O && f->type <= UPP_X))
		cast_unsigned((unsigned long long*)n, ap, f);
	else
		cast_signed((long long*)n, ap, f);
	len = get_format_number1(f, n, str);
	free(n);
	return (len);
}
