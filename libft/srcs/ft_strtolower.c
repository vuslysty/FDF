/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 20:01:50 by vuslysty          #+#    #+#             */
/*   Updated: 2019/05/19 20:01:52 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strtolower(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = 'a' + (*str - 'A');
		str++;
	}
}
