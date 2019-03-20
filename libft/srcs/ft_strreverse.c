/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:07:45 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 20:08:20 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreverse(char *str)
{
	int		len;
	int		i;
	int		j;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	j = len - 1;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i++] = str[j];
		str[j--] = tmp;
	}
}
