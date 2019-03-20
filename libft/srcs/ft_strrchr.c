/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:45:15 by vuslysty          #+#    #+#             */
/*   Updated: 2018/10/25 15:55:59 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*chr;
	int		len;

	chr = (char*)s;
	len = ft_strlen(chr);
	while (len >= 0 && *(chr + len) != (char)c)
		len--;
	if (*(chr + len) == (char)c)
		return (chr + len);
	return (NULL);
}
