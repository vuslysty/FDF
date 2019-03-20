/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:36:56 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/06 14:28:07 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((t_byte*)dst)[i] = ((t_byte*)src)[i];
		if (((t_byte*)dst)[i] == (t_byte)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
