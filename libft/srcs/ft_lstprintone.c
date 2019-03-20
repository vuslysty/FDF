/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:34:26 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/06 21:45:40 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintone(t_list *list)
{
	if (!list)
		return ;
	while (*(char*)(list->content))
	{
		ft_putchar(*(char*)(list->content));
		(list->content)++;
	}
}
