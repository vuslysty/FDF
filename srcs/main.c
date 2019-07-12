/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:10:01 by vuslysty          #+#    #+#             */
/*   Updated: 2019/07/12 17:10:02 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include "math.h"
#define L_UP 	fdf->corner[0].z
#define L_DOWN	fdf->corner[2].z
#define R_UP 	fdf->corner[1].z
#define R_DOWN 	fdf->corner[3].z

int				close_fdf(void *param)
{
	(void)param;
	exit(0);
}

static int		key_hook(int kcode, void *data)
{
	t_fdf			*fdf;
	t_fps			fps;

	fdf = (t_fdf*)data;
	start_fps(&fps, fdf);
	set_param(kcode, fdf);
	do_operations(fdf);
	end_fps(&fps, fdf);
	return (0);
}

void			add_color_to_white_map(t_map *map)
{
	t_2d			p;
	t_point			start;
	t_point			end;
	t_point			curr;
	t_point			delta;

	start.x = map->min_z;
	start.y = 0;
	start.color = 0x00ff00;
	end.x = map->max_z;
	end.y = 0;
	end.color = 0xff0000;
	delta.x = map->max_z - map->min_z;
	delta.y = 0;
	curr.y = 0;
	p.y = -1;
	while (++p.y < map->rows)
	{
		p.x = -1;
		while (++p.x < map->cols)
		{
			curr.x = map->bas[p.y][p.x].z;
			map->bas[p.y][p.x].color = get_color(curr, start, end, delta);
		}
	}
}

int				main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		ft_error("usage:  ./fdf [filename]\n");
	first_init(argv[1], &fdf);
	do_operations(&fdf);
	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, close_fdf, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
