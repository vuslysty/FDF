/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_strnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:58:02 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 16:58:05 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*conv_to_strnum(int *mas, int len)
{
	char	*str;
	int		flag;
	int		i;

	str = (char*)ft_memalloc(len + 1);
	flag = 1;
	i = -1;
	while (--len >= 0)
	{
		if (flag == 1)
		{
			if (mas[len] == 0)
				continue;
			else
				flag = 0;
		}
		str[++i] = '0' + mas[len];
	}
	free(mas);
	return (str);
}
