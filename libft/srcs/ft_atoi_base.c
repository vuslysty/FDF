/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:26:55 by vuslysty          #+#    #+#             */
/*   Updated: 2019/05/19 18:27:00 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				is_valid_char(const char *str, char curr,
										int base, int *n)
{
	int					i;

	i = 0;
	while (str[i] != '\0' && i < base)
	{
		if (str[i] == curr)
		{
			*n = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int						ft_atoi_base(char *str, int base, int sign)
{
	const char			*c = "0123456789abcdef";
	unsigned long int	res;
	int					i;
	int					n;

	if (base < 2 || base > 16)
		return (0);
	res = 0;
	i = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	while ((str[i] != '\0') && is_valid_char(c, str[i], base, &n))
	{
		res = res * base + n;
		i++;
	}
	return ((int)(res * sign));
}
