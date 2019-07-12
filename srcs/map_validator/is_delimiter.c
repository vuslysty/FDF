/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_delimiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:35:33 by vuslysty          #+#    #+#             */
/*   Updated: 2019/07/12 16:35:35 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_delimiter(char c)
{
	if (c == ' ' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	del_list_content(void *content, size_t tmp)
{
	char	**mas;

	if (tmp)
		;
	mas = (char**)content;
	while (*mas)
		free(*mas++);
	free((char**)content);
}
