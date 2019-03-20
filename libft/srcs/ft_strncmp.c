/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:04:17 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/06 17:13:03 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	t_byte *p_s1;
	t_byte *p_s2;
	size_t i;

	if (n == 0)
		return (0);
	p_s1 = (t_byte*)s1;
	p_s2 = (t_byte*)s2;
	i = 0;
	while (p_s1[i] == p_s2[i] && p_s1[i] != '\0' && p_s2[i] != '\0' && --n > 0)
		i++;
	return ((int)(p_s1[i] - p_s2[i]));
}
