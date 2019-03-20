/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:43:32 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:43:49 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	addition_options(t_pf *pf, char **str)
{
	size_t	i;

	if (!ft_strncmp(*str, "{NORMAL}", i = 8))
		set_color(pf, NORMAL, i, str);
	else if (!ft_strncmp(*str, "{BOLD}", i = 6))
		set_color(pf, BOLD, i, str);
	else if (!ft_strncmp(*str, "{DBOLD}", i = 7))
		set_color(pf, DBOLD, i, str);
	else if (!ft_strncmp(*str, "{NBOLD}", i = 7))
		set_color(pf, NBOLD, i, str);
	else if (!ft_strncmp(*str, "{UNDERLINE}", i = 11))
		set_color(pf, UNDERLINE, i, str);
	else if (!ft_strncmp(*str, "{BLINK}", i = 7))
		set_color(pf, BLINK, i, str);
	else if (!ft_strncmp(*str, "{INVERSE}", i = 9))
		set_color(pf, INVERSE, i, str);
	else
		i = 0;
	return (i);
}

size_t	bg_color(t_pf *pf, char **str)
{
	size_t	i;

	if (!ft_strncmp(*str, "{BGSTD}", i = 7))
		set_color(pf, BGSTD, i, str);
	else if (!ft_strncmp(*str, "{BGRED}", i = 7))
		set_color(pf, BGRED, i, str);
	else if (!ft_strncmp(*str, "{BGGREEN}", i = 9))
		set_color(pf, BGGREEN, i, str);
	else if (!ft_strncmp(*str, "{BGYELLOW}", i = 10))
		set_color(pf, BGYELLOW, i, str);
	else if (!ft_strncmp(*str, "{BGBLUE}", i = 8))
		set_color(pf, BGBLUE, i, str);
	else if (!ft_strncmp(*str, "{BGPURPLE}", i = 10))
		set_color(pf, BGPURPLE, i, str);
	else if (!ft_strncmp(*str, "{BGCYAN}", i = 8))
		set_color(pf, BGCYAN, i, str);
	else if (!ft_strncmp(*str, "{BGGRAY}", i = 8))
		set_color(pf, BGGRAY, i, str);
	else
		i = 0;
	return (i);
}

size_t	text_color(t_pf *pf, char **str)
{
	size_t	i;

	if (!ft_strncmp(*str, "{STD}", i = 5))
		set_color(pf, STD, i, str);
	else if (!ft_strncmp(*str, "{RED}", i = 5))
		set_color(pf, RED, i, str);
	else if (!ft_strncmp(*str, "{GREEN}", i = 7))
		set_color(pf, GREEN, i, str);
	else if (!ft_strncmp(*str, "{YELLOW}", i = 8))
		set_color(pf, YELLOW, i, str);
	else if (!ft_strncmp(*str, "{BLUE}", i = 6))
		set_color(pf, BLUE, i, str);
	else if (!ft_strncmp(*str, "{PURPLE}", i = 8))
		set_color(pf, PURPLE, i, str);
	else if (!ft_strncmp(*str, "{CYAN}", i = 6))
		set_color(pf, CYAN, i, str);
	else if (!ft_strncmp(*str, "{EOC}", i = 5))
		set_color(pf, EOC, i, str);
	else if (!ft_strncmp(*str, "{GRAY}", i = 6))
		set_color(pf, GRAY, i, str);
	else
		i = 0;
	return (i);
}

void	set_color(t_pf *pf, char *color, size_t i, char **str)
{
	int		color_len;

	color_len = ft_strlen(color);
	ft_putmem_fd(pf->tmp, pf->i, pf->fd);
	pf->len += pf->i;
	ft_putmem_fd(color, color_len, pf->fd);
	pf->len += color_len;
	*str = *str + (i - 1);
	pf->tmp = *str + 1;
	pf->i = -1;
}
