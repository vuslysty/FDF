/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:35:50 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/01 18:12:56 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len++;
	while (n || len == 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	rec(int nb, int *i, char *str)
{
	if (nb / 10 != 0)
		rec(nb / 10, i, str);
	if (nb < 0)
		str[(*i)++] = (nb % 10 * (-1)) + '0';
	else
		str[(*i)++] = (nb % 10) + '0';
}

char		*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	nbr = (char*)ft_memalloc(sizeof(char) * (nbrlen(n) + 1));
	if (nbr == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
		nbr[i++] = '-';
	rec(n, &i, nbr);
	nbr[i] = '\0';
	return (nbr);
}
