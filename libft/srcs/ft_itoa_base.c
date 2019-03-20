/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:08:02 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:56:21 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_itoa_base(int n, int base, char **str, int *len)
{
	(*len)++;
	if (n > 0 ? n < base : n > -base)
	{
		*str = (char*)ft_memalloc(((size_t)(n > 0 ? *len : ++(*len)) + 1));
		if (n < 0 && base == 10)
			*((*str)++) = '-';
	}
	else
		rec_itoa_base(n / base, base, str, len);
	**str = write_digit_base((n > 0 ? n : -n) % base);
	(*str)++;
}

char		*ft_itoa_base(int nbr, int base)
{
	char	*str;
	int		len;

	len = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	rec_itoa_base(nbr, base, &str, &len);
	return (str - len);
}
