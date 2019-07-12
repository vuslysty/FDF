/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:46:37 by vuslysty          #+#    #+#             */
/*   Updated: 2019/07/12 16:46:39 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	init_values(t_point *delta, t_point *sign, t_point *a, t_point *b)
{
	delta->x = ABS(b->x - a->x);
	delta->y = ABS(b->y - a->y);
	sign->x = a->x < b->x ? 1 : -1;
	sign->y = a->y < b->y ? 1 : -1;
}

void		draw_color_line(t_point *a, t_point *b, t_fdf *fdf, t_point curr)
{
	t_point	delta;
	t_point	sign;
	int		error;
	int		error2;

	init_values(&delta, &sign, a, b);
	error = delta.x - delta.y;
	fdf->img.frame[b->y][b->x] = a->color;
	curr = *a;
	while (curr.x != b->x || curr.y != b->y)
	{
		fdf->img.frame[curr.y][curr.x] = a->color;
		error2 = error * 2;
		if (error2 > -delta.y)
		{
			error -= delta.y;
			curr.x += sign.x;
		}
		if (error2 < delta.x)
		{
			error += delta.x;
			curr.y += sign.y;
		}
	}
}

void		draw_white_line(t_point *a, t_point *b, t_fdf *fdf, t_point curr)
{
	t_point	delta;
	t_point sign;
	int		error;
	int		error2;

	init_values(&delta, &sign, a, b);
	error = delta.x - delta.y;
	fdf->img.frame[b->y][b->x] = 0xffffff;
	curr = *a;
	while (curr.x != b->x || curr.y != b->y)
	{
		fdf->img.frame[curr.y][curr.x] = 0xffffff;
		error2 = error * 2;
		if (error2 > -delta.y)
		{
			error -= delta.y;
			curr.x += sign.x;
		}
		if (error2 < delta.x)
		{
			error += delta.x;
			curr.y += sign.y;
		}
	}
}

void		draw_gradient_line_h(t_point a, t_point b, t_fdf *fdf, t_point curr)
{
	t_point	delta;
	t_point sign;
	int		error;
	int		error2;

	init_values(&delta, &sign, &a, &b);
	error = delta.x - delta.y;
	fdf->help.frame[b.y][b.x] = b.color | 0x55000000;
	curr = a;
	while (curr.x != b.x || curr.y != b.y)
	{
		curr.color = get_color(curr, a, b, delta) | 0x55000000;
		fdf->help.frame[curr.y][curr.x] = curr.color;
		error2 = error * 2;
		if (error2 > -delta.y)
		{
			error -= delta.y;
			curr.x += sign.x;
		}
		if (error2 < delta.x)
		{
			error += delta.x;
			curr.y += sign.y;
		}
	}
}

void		draw_gradient_line(t_point *a, t_point *b, t_fdf *fdf, t_point curr)
{
	t_point	delta;
	t_point sign;
	int		error;
	int		error2;

	init_values(&delta, &sign, a, b);
	error = delta.x - delta.y;
	fdf->img.frame[b->y][b->x] = b->color;
	curr = *a;
	while (curr.x != b->x || curr.y != b->y)
	{
		curr.color = get_color(curr, *a, *b, delta);
		fdf->img.frame[curr.y][curr.x] = curr.color;
		error2 = error * 2;
		if (error2 > -delta.y)
		{
			error -= delta.y;
			curr.x += sign.x;
		}
		if (error2 < delta.x)
		{
			error += delta.x;
			curr.y += sign.y;
		}
	}
}
