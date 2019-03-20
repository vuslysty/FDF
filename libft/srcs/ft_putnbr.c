/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:47:54 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/01 18:20:47 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec(int nb)
{
	if (nb / 10 != 0)
		rec(nb / 10);
	if (nb < 0)
		ft_putchar((nb % 10 * (-1)) + '0');
	else
		ft_putchar((nb % 10) + '0');
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	rec(n);
}
