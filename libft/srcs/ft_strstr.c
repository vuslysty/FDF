/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:05:26 by vuslysty          #+#    #+#             */
/*   Updated: 2018/10/25 16:52:56 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		pos;

	if (*needle == '\0')
		return ((char*)haystack);
	i = -1;
	while (haystack[++i] != '\0')
	{
		j = 0;
		pos = i;
		while (haystack[i] == needle[j])
		{
			if ((haystack[i + 1] == '\0' && needle[j + 1] == '\0') ||
				(haystack[i + 1] != '\0' && needle[j + 1] == '\0'))
				return ((char*)(haystack + pos));
			i++;
			j++;
		}
		i = pos;
	}
	return (NULL);
}
