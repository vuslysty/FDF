/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_options.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:30:27 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/25 11:31:52 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		b_flag_plus(char **buf, int bits, int spaces)
{
	char	*tmp_buf;
	int		i;
	char	*tmp;
	char	*formated_binary;

	tmp_buf = *buf;
	tmp = (char*)ft_memalloc_chr((bits + spaces + 1), ' ');
	formated_binary = tmp;
	i = 0;
	while (*tmp_buf != 0)
	{
		if (++i % 9 == 0 && spaces--)
		{
			tmp++;
			i = 0;
			continue;
		}
		*tmp++ = *tmp_buf++;
	}
	free(*buf);
	*buf = formated_binary;
}

void		b_size_mode_t(char *buf, void *b, t_format *f)
{
	int		i;

	i = 0;
	while (*(char*)b != 0)
	{
		read_binary(b, f, buf + i, 8);
		i += 8;
		b = (char*)b + 1;
	}
}

int			b_flag_nozero(t_format *f, int len, char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *str;
	if (f->zero == 0)
	{
		while (*tmp == '0')
		{
			i++;
			tmp++;
		}
		tmp = ft_strdup(tmp);
		free(*str);
		*str = tmp;
	}
	return (len - i);
}

size_t		get_format_binary(t_format *f, char **str, int lb)
{
	char	*buf;
	size_t	ls;

	buf = *str;
	f->minus ? f->zero = 0 : 0;
	if (f->w_val > lb)
		*str = ft_memalloc_chr(f->w_val + 1, ' ');
	else
		*str = ft_memalloc_chr(lb + 1, ' ');
	ls = f->w_val > lb ? f->w_val : lb;
	if (f->minus)
		ft_memmove(*str, buf, lb);
	else
		ft_memmove(*str + (ls - lb), buf, lb);
	free(buf);
	return (ls);
}

void		b_flag_precision(t_format *f, char *str)
{
	int		i;

	i = 0;
	if (f->precision && f->p_val > 0)
	{
		f->w_val = 0;
		while (*str != 0)
		{
			if (*str == ' ')
			{
				i++;
				if (i == f->p_val)
				{
					*str = '\n';
					i = 0;
				}
			}
			str++;
		}
	}
}
