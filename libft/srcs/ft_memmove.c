/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:58:27 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/06 14:48:09 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	ret = dst;
	if (dst < src)
		while ((size_t)(dst - ret) < len)
			*(t_byte*)dst++ = *(t_byte*)src++;
	else
		while (len-- > 0)
			((t_byte*)dst)[len] = ((t_byte*)src)[len];
	return (ret);
}
