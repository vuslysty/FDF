/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:44:12 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/16 17:44:23 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *mem1, size_t len1, void *mem2, size_t len2)
{
	void	*buf;

	buf = malloc(len1 + len2 + 1);
	ft_memmove(buf, mem1, len1);
	ft_memmove(buf + len1, mem2, len2);
	return (buf);
}
