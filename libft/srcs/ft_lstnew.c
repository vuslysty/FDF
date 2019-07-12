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

	list = (t_list*)ft_memalloc(sizeof(t_list));
	if (list)
	{
		list->next = NULL;
		list->content = (void*)content;
		list->content_size = content_size;
	}
	return (list);
}
