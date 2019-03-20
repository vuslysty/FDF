/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:43:31 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 20:06:30 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_chr(unsigned char c)
{
	write(1, &c, 1);
}

void			ft_putchar(size_t c)
{
	if (c < 128)
		print_chr(c);
	else if (c < 2048)
	{
		print_chr((c >> 6) + 0xc0);
		print_chr((c & 0x3f) + 0x80);
	}
	else if (c < 65536)
	{
		print_chr((c >> 12) + 0xe0);
		print_chr(((c >> 6) & 0x3f) + 0x80);
		print_chr((c & 0x3f) + 0x80);
	}
	else if (c < 2097152)
	{
		print_chr((c >> 18) + 0xf0);
		print_chr(((c >> 12) & 0x3f) + 0x80);
		print_chr(((c >> 6) & 0x3f) + 0x80);
		print_chr((c & 0x3f) + 0x80);
	}
}
