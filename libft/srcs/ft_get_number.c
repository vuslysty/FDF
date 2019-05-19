/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 20:00:37 by vuslysty          #+#    #+#             */
/*   Updated: 2019/05/19 20:00:39 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_number(char *str)
{
	int		num;
	int		sign;

	if (str == NULL)
		return (0);
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	str = ft_strdup(str);
	ft_strtolower(str);
	if (!ft_strncmp("0b", str, 2))
		num = ft_atoi_base(str + 2, 2, sign);
	else if (!ft_strncmp("0x", str, 2))
		num = ft_atoi_base(str + 2, 16, sign);
	else if (!ft_strncmp("0", str, 1))
		num = ft_atoi_base(str + 1, 8, sign);
	else
		num = ft_atoi_base(str, 10, sign);
	free(str);
	return (num);
}
