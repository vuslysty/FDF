/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:32:21 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/26 16:40:33 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_right_count_mem(t_format *f, char **buf, void *str)
{
	int		bytes;

	if (f->size == 0)
	{
		f->size = 1;
		f->s_val = 2;
	}
	bytes = 0;
	if (f->s_val == 6)
		while (*(char*)str++ != 0)
			bytes++;
	else if (f->s_val == 0)
		bytes = 1;
	else if (f->s_val == 1)
		bytes = 2;
	else if (f->s_val == 2 || f->s_val == 5)
		bytes = 8;
	else if (f->s_val == 3)
		bytes = 4;
	else
		bytes = 10;
	*buf = (char*)ft_memalloc((bytes * 8) + 1);
	return (bytes * 8);
}

static void		for_long_double(void *b, char *str)
{
	int		i;
	int		shift;

	i = 0;
	shift = 16;
	while (--shift >= 0)
		str[i++] = (*((short int*)b + 4) >> shift & 0b1) + '0';
	shift = 64;
	while (--shift >= 0)
		str[i++] = (*(t_ll*)b >> shift & 0b1) + '0';
}

void			read_binary(void *b, t_format *f, char *str, int bits)
{
	int		i;

	i = 0;
	if (f->size)
		while (--bits >= 0)
		{
			if (f->s_val == 0 || f->s_val == 6)
				str[i++] = (*(t_byte*)b >> bits & 0b1) + '0';
			else if (f->s_val == 1)
				str[i++] = (*(short int*)b >> bits & 0b1) + '0';
			else if (f->s_val == 2 || f->s_val == 5)
				str[i++] = (*(t_ll*)b >> bits & 0b1) + '0';
			else if (f->s_val == 3)
				str[i++] = (*(int*)b >> bits & 0b1) + '0';
			else
			{
				for_long_double(b, str);
				break ;
			}
		}
}

static void		get_rigth_param(t_format *f, void **b, va_list *ap, t_conv *c)
{
	f->s_val == 6 || f->plus ? f->zero = 1 : 0;
	if (f->s_val == 4)
	{
		c->ld = va_arg(*ap, long double);
		*b = &c->ld;
	}
	else if (f->s_val == 5)
	{
		c->d = va_arg(*ap, double);
		*b = &c->d;
	}
	else if (f->s_val == 6)
	{
		c->str = va_arg(*ap, char*);
		*b = c->str;
	}
	else
	{
		c->li = va_arg(*ap, long int);
		*b = &c->li;
	}
}

size_t			f_b(t_format *f, va_list *ap, char **buf)
{
	int		spaces;
	void	*b;
	int		bits;
	t_conv	c;

	get_rigth_param(f, &b, ap, &c);
	bits = get_right_count_mem(f, buf, b);
	if (f->s_val == 6)
		b_size_mode_t(*buf, b, f);
	else
		read_binary(b, f, *buf, bits);
	if (f->plus)
	{
		spaces = (bits / 8) - 1;
		spaces < 0 ? spaces = 0 : 0;
		b_flag_plus(buf, bits, spaces);
		bits = bits + spaces;
		b_flag_precision(f, *buf);
	}
	bits = b_flag_nozero(f, bits, buf);
	bits = get_format_binary(f, buf, bits);
	return (bits);
}
