/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:54:45 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/07 14:31:58 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespaces(char const *s)
{
	if (*s == '\n' || *s == ' ' || *s == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (ft_whitespaces(&s[i]))
		i++;
	j = ft_strlen(s) - 1;
	while (ft_whitespaces(&s[j]) && j >= 0)
		j--;
	if (i > j)
	{
		newstr = ft_strdup("");
		return (newstr);
	}
	newstr = ft_strsub(s, i, j - i + 1);
	if (newstr == NULL)
		return (NULL);
	return (newstr);
}
