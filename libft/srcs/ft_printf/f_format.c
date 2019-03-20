/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:50:08 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 18:50:30 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_format(t_myfloat *mf, t_format *f)
{
	char	*strnum;

	round_numstr(mf, f->p_val);
	if (f->p_val != 0 || f->sharp)
		mf->intnum = ft_strjoin_free(mf->intnum, ".", 0);
	if (f->p_val == 0)
		strnum = ft_strdup(mf->intnum);
	else
		strnum = ft_strjoin(mf->intnum, mf->decimal);
	return (strnum);
}
