/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:42:00 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 18:43:30 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	e_plus(t_myfloat *mf, t_format *f)
{
	if (mf->exp_sign == 0 && mf->exp_count != 0)
	{
		if (mf->len_i > 1)
		{
			mf->decimal = ft_strjoin_free(mf->intnum + 1, mf->decimal, 1);
			mf->intnum[1] = '\0';
		}
		mf->len_d = ft_strlen(mf->decimal);
		mf->len_i = ft_strlen(mf->intnum);
		round_numstr(mf, f->p_val);
		if (mf->len_i > 1)
		{
			mf->exp_count += mf->len_i - 1;
			e_plus(mf, f);
		}
	}
	round_numstr(mf, f->p_val);
}

static void	e_minus(t_myfloat *mf)
{
	char	*tmp;

	tmp = mf->decimal;
	mf->intnum[0] = mf->decimal[mf->exp_count - 1];
	mf->decimal = ft_strdup(mf->decimal + mf->exp_count);
	free(tmp);
	mf->len_d = ft_strlen(mf->decimal);
	mf->len_i = ft_strlen(mf->intnum);
}

static void	right_round(t_myfloat *mf, t_format *f)
{
	int		round;

	if (mf->intnum[0] == '0')
		round = f->p_val + mf->exp_count;
	else
		round = f->p_val;
	if (round >= 0)
		round_numstr(mf, round);
}

char		*e_format(t_myfloat *mf, t_format *f)
{
	char	*strnum;
	char	*pow;

	get_exp_count(mf);
	right_round(mf, f);
	get_exp_count(mf);
	if (mf->exp_sign == 1 && mf->exp_count != 0)
		e_minus(mf);
	e_plus(mf, f);
	if (f->p_val != 0 || f->sharp)
		mf->intnum = ft_strjoin_free(mf->intnum, ".", 0);
	if (f->p_val == 0)
		strnum = ft_strdup(mf->intnum);
	else
		strnum = ft_strjoin(mf->intnum, mf->decimal);
	strnum = ft_strjoin_free(strnum, f->type == E ? "e" : "E", 0);
	strnum = ft_strjoin_free(strnum, mf->exp_sign ? "-" : "+", 0);
	pow = ft_itoa(mf->exp_count);
	add_0_for_numstr(&pow, 2, 1);
	strnum = ft_strjoin_free(strnum, pow, 0);
	free(pow);
	return (strnum);
}
