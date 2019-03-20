/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:39:30 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/26 18:04:05 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_nbr(char **nbr, t_format *f, int len, char *tmp)
{
	if (f->zero && f->w_val > len + 1 && !f->precision)
	{
		*nbr = ft_memalloc_chr(f->w_val - 1, '0');
		ft_memmove(*nbr + (f->w_val - 2 - len), tmp, len);
	}
	else if (len == 1 && tmp[0] == '0' && f->precision && f->p_val == 0 &&
			f->type != O)
		*nbr = ft_strdup("");
	else if (f->precision && f->p_val > len)
	{
		*nbr = ft_memalloc_chr(f->p_val + 1, '0');
		ft_memmove(*nbr + (f->p_val - len), tmp, len);
	}
	else
		*nbr = ft_strdup(tmp);
	free(tmp);
}

void		min_plus_space(char **nbr, t_format *f)
{
	char	*tmp;

	if (((f->type >= D && f->type <= I) || (f->type >= F && f->type <= UPP_G))
		&& (f->sign || f->plus || f->space))
	{
		tmp = *nbr;
		if (f->sign)
			*nbr = ft_strjoin("-", *nbr);
		else
			*nbr = ft_strjoin((f->plus ? "+" : " "), *nbr);
		free(tmp);
	}
}

static void	check_pox(t_format *f, char **str)
{
	char	*tmp;

	tmp = *str;
	if (f->sharp && (f->type == O || f->type == X || f->type == UPP_X ||
		f->type == P))
	{
		if (f->type == O)
			*str = ft_strjoin("0", *str);
		else
			*str = ft_strjoin("0x", *str);
		free(tmp);
	}
	if (f->type == UPP_X)
		ft_strtoupper(*str);
}

size_t		number_format(char **nbr, t_format *f)
{
	int		len;
	char	*tmp;

	f->sign = (*nbr)[0] == '-' ? 1 : 0;
	tmp = ft_strdup(*nbr + f->sign);
	free(*nbr);
	if (f->type == O)
		check_pox(f, &tmp);
	len = ft_strlen(tmp);
	set_nbr(nbr, f, len, tmp);
	if (f->type != O)
		check_pox(f, nbr);
	min_plus_space(nbr, f);
	return (ft_strlen(*nbr));
}
