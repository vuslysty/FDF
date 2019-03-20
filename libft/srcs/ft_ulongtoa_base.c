/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulongtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:10:04 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 20:11:34 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_ultoa_base(unsigned long long n, int base, char **str, int *len)
{
	(*len)++;
	if (n < (unsigned long long)base)
		*str = (char*)ft_memalloc(sizeof(char) * (*len + 1));
	else
		rec_ultoa_base(n / base, base, str, len);
	**str = write_digit_base((int)(n % base));
	(*str)++;
}

char		*ft_ultoa_base(unsigned long long n, int base)
{
	char	*str;
	int		len;

	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	rec_ultoa_base((long long)n, base, &str, &len);
	return (str - len);
}
