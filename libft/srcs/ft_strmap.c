/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:51:31 by vuslysty          #+#    #+#             */
/*   Updated: 2018/10/30 21:13:39 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = -1;
	if (s == NULL)
		return (NULL);
	str = ft_memalloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[++i] != '\0')
		str[i] = f(s[i]);
	str[i] = '\0';
	return (str);
}
