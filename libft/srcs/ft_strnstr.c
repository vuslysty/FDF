/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:23:31 by vuslysty          #+#    #+#             */
/*   Updated: 2018/10/25 20:25:36 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int j;
	int pos;
	int save_len;

	if (*needle == '\0')
		return ((char*)haystack);
	i = -1;
	while (haystack[++i] != '\0' && len > 0)
	{
		j = -1;
		pos = i;
		save_len = len;
		while (haystack[i] == needle[++j] && len > 0)
		{
			if ((haystack[i + 1] == '\0' && needle[j + 1] == '\0') ||
				(haystack[i + 1] != '\0' && needle[j + 1] == '\0'))
				return ((char*)(haystack + pos));
			len--;
			i++;
		}
		len = --save_len;
		i = pos;
	}
	return (NULL);
}
