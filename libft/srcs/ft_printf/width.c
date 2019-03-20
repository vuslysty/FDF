/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:45:10 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:45:19 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width(t_format *form, char **str, va_list *ap)
{
	if (**str == '*')
	{
		form->w_val = va_arg(*ap, int);
		*str = *str + 1;
	}
	else
	{
		form->w_val = ft_atoi(*str);
		while (ft_isdigit(**str))
			*str = *str + 1;
	}
}
