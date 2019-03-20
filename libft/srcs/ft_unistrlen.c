/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:43:23 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/25 12:43:39 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_unistrlen(unsigned char *str)
{
	size_t	len;
	int		i;

	len = 0;
	while (*str != 0)
	{
		if (*str >> 7 == 0)
			i = 1;
		else if (*str >> 5 == 6)
			i = 2;
		else if (*str >> 4 == 14)
			i = 3;
		else
			i = 4;
		len++;
		str += i;
	}
	return (len);
}
