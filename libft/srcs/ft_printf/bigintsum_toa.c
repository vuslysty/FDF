/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigintsum_toa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:51:45 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 16:53:30 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_len_and_makesame(char **num1, char **num2, int m)
{
	size_t	len1;
	size_t	len2;
	size_t	len;
	char	*tmp;

	len1 = ft_strlen(*num1);
	len2 = ft_strlen(*num2);
	len = (len1 > len2) ? len1 : len2;
	if (len1 == len2)
		return (len);
	tmp = ft_memalloc_chr(len + 1, '0');
	if (len1 > len2)
	{
		ft_memmove(tmp + (m ? 0 : len - len2), *num2, len2);
		free(*num2);
		*num2 = tmp;
	}
	else
	{
		ft_memmove(tmp + (m ? 0 : len - len1), *num1, len1);
		free(*num1);
		*num1 = tmp;
	}
	return (len);
}

char			*bigintsum_toa(char *num1, char *num2, int mode)
{
	size_t		len;
	int			*mas;
	size_t		i;

	num1 = ft_strdup(num1);
	ft_strreverse(num1);
	num2 = ft_strdup(num2);
	ft_strreverse(num2);
	len = get_len_and_makesame(&num1, &num2, mode);
	mas = (int*)ft_memalloc(sizeof(int) * (len + 1));
	i = -1;
	while (++i < len)
	{
		mas[i] += (num1[i] - '0') + (num2[i] - '0');
		if (mas[i] >= 10)
		{
			mas[i + 1] += mas[i] / 10;
			mas[i] %= 10;
		}
	}
	free(num1);
	free(num2);
	return (conv_to_strnum(mas, len + 1));
}
