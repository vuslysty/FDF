/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:56:51 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/26 19:17:53 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_ltoa_base(long long n, int base, char **str, int *len)
{
	int		tmp;

	(*len)++;
	if (n > 0 ? n < base : n > -base)
	{
		*str = (char*)ft_memalloc(((size_t)(n > 0 ? *len : ++(*len)) + 1));
		if (n < 0)
			*((*str)++) = '-';
	}
	else
		rec_ltoa_base(n / base, base, str, len);
	if (n < -9223372036854775807)
		tmp = 8;
	else
		tmp = (n > 0 ? n : -n) % base;
	**str = write_digit_base(tmp);
	(*str)++;
}

char		*ft_ltoa_base(long long n, int base)
{
	char	*str;
	int		len;

	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	rec_ltoa_base(n, base, &str, &len);
	return (str - len);
}
