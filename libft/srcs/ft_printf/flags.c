/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:59:05 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:00:04 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(t_format *form, char **str)
{
	if (**str == '+')
		form->plus = 1;
	else if (**str == '-')
		form->minus = 1;
	else if (**str == ' ')
		form->space = 1;
	else if (**str == '#')
		form->sharp = 1;
	else if (**str == '0')
		form->zero = 1;
	*str = *str + 1;
}
