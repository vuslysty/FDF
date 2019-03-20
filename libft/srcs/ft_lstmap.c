/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:03:34 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/06 14:22:04 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*begin_tmp;

	if (lst == NULL)
		return (NULL);
	temp = f(lst);
	begin_tmp = temp;
	if (begin_tmp == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		if (temp->next == NULL)
			return (NULL);
		temp = temp->next;
	}
	return (begin_tmp);
}
