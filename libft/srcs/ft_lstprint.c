/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:46:47 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 20:02:17 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *list)
{
	int	i;

	i = 0;
	if (!list)
		return ;
	while (list)
	{
		ft_putnbr(++i);
		ft_putstr(" -> ");
		ft_putstr(list->content);
		ft_putstr("    ");
		ft_putnbr((int)list->content_size);
		ft_putchar('\n');
		list = list->next;
	}
}
