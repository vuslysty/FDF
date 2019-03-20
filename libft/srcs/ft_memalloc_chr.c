/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:02:45 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 20:03:08 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc_chr(size_t size, char c)
{
	void	*mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	if (size > 1)
		ft_memset(mem, c, size - 1);
	((t_byte*)mem)[size - 1] = '\0';
	return (mem);
}
