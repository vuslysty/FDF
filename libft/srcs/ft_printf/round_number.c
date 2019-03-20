/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:42:52 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:43:03 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	some_condition(t_myfloat *mf, int round_count)
{
	char	*one;
	char	*tmp;

	if (mf->decimal[round_count] >= '5')
	{
		mf->decimal[round_count] = '\0';
		tmp = mf->decimal;
		one = ft_strdup("1");
		add_0_for_numstr(&one, round_count, 1);
		mf->decimal = bigintsum_toa(one, mf->decimal, 0);
		free(one);
		add_0_for_numstr(&mf->decimal, round_count, 1);
		free(tmp);
		if (round_count != (int)ft_strlen(mf->decimal))
		{
			tmp = mf->intnum;
			mf->intnum = bigintsum_toa(mf->intnum, "1", 1);
			free(tmp);
			tmp = mf->decimal;
			mf->decimal = ft_strdup(mf->decimal + 1);
			free(tmp);
		}
	}
	else
		mf->decimal[round_count] = '\0';
}

void		round_numstr(t_myfloat *mf, int round_count)
{
	if (round_count > mf->len_d)
		add_0_for_numstr(&mf->decimal, round_count, 0);
	if (!(mf->intnum[0] == '0' && mf->exp_count == 0))
	{
		if (round_count < mf->len_d)
			some_condition(mf, round_count);
		mf->len_d = ft_strlen(mf->decimal);
		mf->len_i = ft_strlen(mf->intnum);
	}
}
