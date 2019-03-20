/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:51:22 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/06 14:35:27 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(t_byte*)s1 != *(t_byte*)s2)
			return (*(t_byte*)s1 - *(t_byte*)s2);
		s1++;
		s2++;
	}
	return (0);
}
