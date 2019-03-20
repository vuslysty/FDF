/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:48:28 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/05 15:40:21 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp_1;
	t_list	*temp_2;

	temp_1 = *alst;
	temp_2 = temp_1->next;
	while (temp_2)
	{
		ft_lstdelone(&temp_1, del);
		temp_1 = temp_2;
		temp_2 = temp_2->next;
	}
	ft_lstdelone(&temp_1, del);
	*alst = NULL;
}
