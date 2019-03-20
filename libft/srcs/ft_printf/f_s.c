/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:51:37 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/26 16:44:03 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		alloc_good_width(t_format *f, char **str, int len)
{
	if (f->precision || f->w_val)
	{
		if (f->precision && f->w_val)
			if (f->p_val <= len && f->w_val <= f->p_val)
				*str = (char*)ft_memalloc_chr(f->p_val + 1, ' ');
			else if (f->w_val > len || f->w_val > f->p_val)
				*str = (char*)ft_memalloc_chr(f->w_val + 1, ' ');
			else
				*str = (char*)ft_memalloc_chr(len + 1, ' ');
		else if (f->precision)
			*str = (char*)ft_memalloc_chr(1 +
					(f->p_val <= len ? f->p_val : len), ' ');
		else
			*str = (char*)ft_memalloc_chr((f->w_val > len ?
									f->w_val : len) + 1, ' ');
	}
	else
		*str = (char*)ft_memalloc_chr(len + 1, ' ');
}

static size_t	oper_with_minus(t_format *f, char **str, char *buf, int len_buf)
{
	size_t	len_str;

	len_str = ft_strlen(*str);
	if (f->precision)
		if (f->p_val < len_buf)
		{
			buf[f->p_val] = '\0';
			len_buf = ft_strlen(buf);
		}
	if (f->minus)
		ft_memmove(*str, buf, len_buf);
	else
	{
		if (f->zero)
			ft_memset(*str, '0', len_str - len_buf);
		ft_memmove(*str + (len_str - len_buf), buf, len_buf);
	}
	free(buf);
	return (len_str);
}

size_t			f_s(t_format *form, va_list *ap, char **str)
{
	char	*buf;
	int		len;

	buf = ft_strdup(va_arg(*ap, char*));
	if (buf == NULL)
		buf = ft_strdup("(null)");
	len = ft_strlen(buf);
	alloc_good_width(form, str, len);
	return (oper_with_minus(form, str, buf, len));
}
