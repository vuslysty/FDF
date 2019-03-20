/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_0_for_numstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:50:55 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 16:51:19 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_0_for_numstr(char **num, int len_finish, int mode)
{
	int		len_num;
	char	*tmp;

	len_num = ft_strlen(*num);
	if (len_num < len_finish)
	{
		tmp = (char*)ft_memalloc_chr(len_finish + 1, '0');
		ft_memmove(tmp + (mode ? len_finish - len_num : 0), *num, len_num);
		free(*num);
		*num = tmp;
	}
}
