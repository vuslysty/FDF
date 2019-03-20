/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:17:36 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/06 17:35:45 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_putnbr(int sign, int n, int fd)
{
	if (n != 0)
	{
		recursive_putnbr(sign, n / 10, fd);
		if (sign == 1)
			ft_putchar_fd('0' + (n % 10), fd);
		else
			ft_putchar_fd('0' - (n % 10), fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int		sign;

	sign = 1;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	recursive_putnbr(sign, n, fd);
}
