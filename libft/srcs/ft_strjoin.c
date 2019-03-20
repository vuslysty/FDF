/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:43:24 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 20:07:12 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *s1, char *s2, int mode)
{
	char	*tmp;

	tmp = mode ? s2 : s1;
	if (mode)
		s2 = ft_strjoin(s1, s2);
	else
		s1 = ft_strjoin(s1, s2);
	free(tmp);
	return (mode ? s2 : s1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	newstr = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstr == NULL)
		return (NULL);
	ft_strcpy(newstr, s1);
	ft_strcat(newstr, s2);
	return (newstr);
}
