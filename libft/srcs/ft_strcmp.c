/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:47:58 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/06 15:52:33 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	t_byte	*p_s1;
	t_byte	*p_s2;
	int		i;

	p_s1 = (t_byte*)s1;
	p_s2 = (t_byte*)s2;
	i = 0;
	while (p_s1[i] == p_s2[i] && p_s1[i] != '\0' && p_s2[i] != '\0')
		i++;
	return ((int)(p_s1[i] - p_s2[i]));
}
