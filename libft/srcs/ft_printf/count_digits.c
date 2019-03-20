/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:59:33 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 18:41:29 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(size_t digit)
{
	int	len;

	len = 0;
	while (digit / 10 > 0)
	{
		len++;
		digit /= 10;
	}
	return (++len);
}
