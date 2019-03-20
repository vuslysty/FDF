/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:07:09 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:55:47 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int						ft_atoi(const char *str)
{
	unsigned long int	res;
	int					i;
	int					sign;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == 0)
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		if (sign == 1 && res >= 9223372036854775807)
			return (-1);
		else if (sign == -1 && res > 9223372036854775807)
			return (0);
		i++;
	}
	return ((int)(res * sign));
}
