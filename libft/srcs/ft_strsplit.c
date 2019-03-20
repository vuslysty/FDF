/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:56:26 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/06 15:17:08 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_delim(char *str, char d)
{
	while (*str == d)
		str++;
	return (str);
}

static int	count_str_between_d(char *str, char d)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		str = skip_delim(str, d);
		if (*str != '\0')
		{
			while (*str != '\0' && *str != d)
				str++;
			count++;
		}
	}
	return (count);
}

static char	*strdup_befor_delim(char *str, char d)
{
	char	*new_str;
	int		len;
	int		i;

	len = 0;
	while (str[len] != '\0' && str[len] != d)
		len++;
	new_str = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**mas;
	char	*str;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	str = (char*)s;
	len = count_str_between_d(str, c);
	mas = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	if (mas == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		str = skip_delim(str, c);
		if (*str != '\0')
		{
			mas[i++] = strdup_befor_delim(str, c);
			while (*str != c && *str != '\0')
				str++;
		}
	}
	mas[i] = NULL;
	return (mas);
}
