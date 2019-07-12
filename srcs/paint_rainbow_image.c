/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_rainbow_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:11:45 by vuslysty          #+#    #+#             */
/*   Updated: 2019/07/12 17:11:50 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void		init_raibow_points(t_point rainbow[8])
{
	rainbow[0].x = 0;
	rainbow[0].color = 0x00ff0000;
	rainbow[1].x = 285;
	rainbow[1].color = 0x00ffdd00;
	rainbow[2].x = 570;
	rainbow[2].color = 0x0021ff00;
	rainbow[3].x = 855;
	rainbow[3].color = 0x0000fffa;
	rainbow[4].x = 1140;
	rainbow[4].color = 0x00000cff;
	rainbow[5].x = 1425;
	rainbow[5].color = 0x00c300ff;
	rainbow[6].x = 1710;
	rainbow[6].color = 0x00c300ff;
	rainbow[7].x = 1999;
	rainbow[7].color = 0x00ff0000;
}

void			paint_rainbow(t_fdf *fdf)
{
	int			i;
	int			y;
	t_point		rainbow[8];

	ft_bzero(rainbow, sizeof(rainbow));
	init_raibow_points(rainbow);
	y = -1;
	while (++y < fdf->w_size.y)
	{
		i = -1;
		while (++i < 7)
		{
			draw_gradient_line_h(rainbow[i], rainbow[i + 1], fdf, rainbow[0]);
			rainbow[i].y++;
		}
		rainbow[i].y++;
	}
}
