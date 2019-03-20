/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:01:59 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 20:13:04 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	firstswap(t_list **begin)
{
	t_list	*tmp;

	tmp = (*begin)->next;
	(*begin)->next = tmp->next;
	tmp->next = *begin;
	*begin = tmp;
}

static void	secondswap(t_list *list)
{
	t_list	*first;
	t_list	*second;

	first = list->next;
	second = list->next->next;
	list->next = second;
	first->next = second->next;
	list->next->next = first;
}

void		sort_list(t_list **begin)
{
	t_list	*t;
	int		len;
	int		i;

	len = ft_list_size(*begin);
	while (len >= 2)
	{
		i = 0;
		while (++i < len)
		{
			if (i == 1 && (*begin)->content_size > (*begin)->next->content_size)
				firstswap(begin);
			if (i == 2)
				t = *begin;
			if (i >= 2)
			{
				if (t->next->content_size > t->next->next->content_size)
					secondswap(t);
				t = t->next;
			}
		}
		len--;
	}
}
