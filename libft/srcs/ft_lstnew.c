/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:49:33 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/02 18:27:25 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	size_t	i;

	list = (t_list*)ft_memalloc(sizeof(t_list));
	if (list)
	{
		list->next = NULL;
		if (content == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
			return (list);
		}
		i = 0;
		list->content = ft_memalloc(content_size);
		if (list->content == NULL)
			return (NULL);
		while (content_size--)
		{
			((t_byte*)(list->content))[i] = ((t_byte*)content)[i];
			i++;
		}
		list->content_size = i;
	}
	return (list);
}
