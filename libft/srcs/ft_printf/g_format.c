/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:06:26 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:07:53 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_sharp(char **strnum, t_format *f, t_myfloat *mf)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *strnum;
	if (f->type == E || f->type == UPP_E)
	{
		while (*tmp != 'e' && *tmp != 'E')
		{
			i++;
			tmp++;
		}
		tmp = ft_strdup(tmp);
	}
	else
	{
		tmp = ft_strdup("");
		while ((*strnum)[i] != '\0')
			i++;
	}
	while (!((*strnum)[i] = 0) && mf->len_d && --i >= 0 && (*strnum)[i] == '0')
		;
	(*strnum)[i] == '.' ? (*strnum)[i] = '\0' : 0;
	*strnum = ft_strjoin_free(*strnum, tmp, 0);
	free(tmp);
}

static void		right_round(t_myfloat *mf, t_format *f)
{
	int		round;

	if (mf->intnum[0] == '0')
		round = (f->p_val - mf->len_i) + mf->exp_count;
	else
		round = f->p_val - mf->len_i;
	if (round >= 0)
		round_numstr(mf, round);
}

char			*g_format(t_myfloat *mf, t_format *f)
{
	char	*strnum;

	f->p_val == 0 ? f->p_val = 1 : 0;
	right_round(mf, f);
	get_exp_count(mf);
	if ((mf->intnum[0] == '0' && mf->exp_count > 4) || (mf->len_i > f->p_val))
	{
		f->type = f->type == G ? E : UPP_E;
		f->p_val--;
		strnum = e_format(mf, f);
	}
	else
	{
		f->type = F;
		if (mf->intnum[0] != '0')
			f->p_val = f->p_val - mf->len_i;
		else if (mf->intnum[0] == '0' && mf->exp_count == 0)
			f->p_val--;
		else
			f->p_val = f->p_val + mf->exp_count - 1;
		strnum = f_format(mf, f);
	}
	f->sharp ? 0 : check_sharp(&strnum, f, mf);
	return (strnum);
}
