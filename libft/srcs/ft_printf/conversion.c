/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:58:41 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/26 16:39:03 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_conversation(t_format *f, int const *i)
{
	int count;

	count = -1;
	while (++count < 17)
		*i == count ? f->type = count : 0;
}

int			conversion(t_format *form, char **str)
{
	int	i;

	i = -1;
	while (CONVERSIONS[++i] != '\0')
		if (CONVERSIONS[i] == **str)
		{
			set_conversation(form, &i);
			*str = *str + 1;
			return (1);
		}
	return (0);
}
