/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:27:13 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/01 14:58:08 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (len > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	if (len != 0)
		while (len > 0)
		{
			dst[i++] = '\0';
			len--;
		}
	return (dst);
}
