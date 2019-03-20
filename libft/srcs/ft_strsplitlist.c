/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:29:51 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/07 11:50:31 by vuslysty         ###   ########.fr       */
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

t_list		*ft_strsplitlist(char *str, char c)
{
	t_list	*list;
	int		len;
	char	*temp;

	list = NULL;
	if (str == NULL)
		return (NULL);
	len = count_str_between_d(str, c);
	while (len--)
	{
		str = skip_delim(str, c);
		temp = strdup_befor_delim(str, c);
		ft_lstadd_end(&list, ft_lstnew(temp, ft_strlen(temp) + 1));
		while (*str != c && *str != '\0')
			str++;
	}
	return (list);
}
