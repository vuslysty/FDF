/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_number1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:09:33 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/26 18:00:41 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define SIGN (buf[0] == '-' || buf[0] == '+' || buf[0] == ' ')
#define SPACES_OR_ZEROS f->zero && !f->precision ? '0' : ' '

static char	*get_good_func(void *n, t_format *f)
{
	char	*buf;
	int		base;

	if (f->type == D || f->type == I || f->type == U)
		base = 10;
	else if (f->type == O)
		base = 8;
	else
		base = 16;
	if (f->type == D || f->type == I)
		buf = ft_ltoa_base(*(long long*)n, base);
	else
		buf = ft_ultoa_base(*(unsigned long long*)n, base);
	if (f->type != P && buf[0] == '0')
	{
		if (f->precision)
			buf[0] = '\0';
		if (f->type != O)
			f->sharp = 0;
	}
	return (buf);
}

size_t		get_format_number1(t_format *f, void *n, char **str)
{
	char	*buf;
	int		lb;
	int		ls;

	buf = get_good_func(n, f);
	lb = number_format(&buf, f);
	if (f->w_val > lb)
		*str = ft_memalloc_chr(f->w_val + 1, SPACES_OR_ZEROS);
	else
		*str = ft_memalloc_chr(lb + 1, ' ');
	ls = f->w_val > lb ? f->w_val : lb;
	if (f->minus)
		ft_memmove(*str, buf, lb);
	else
	{
		if (f->w_val > lb && f->zero && !f->precision && SIGN)
		{
			ft_memmove(*str + (ls - lb + 1), buf + 1, lb - 1);
			(*str)[0] = buf[0];
		}
		else
			ft_memmove(*str + (ls - lb), buf, lb);
	}
	free(buf);
	return (ls);
}
