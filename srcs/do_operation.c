/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:40:52 by vuslysty          #+#    #+#             */
/*   Updated: 2019/07/12 16:40:59 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

static void	init_res_map(t_map *map, t_fdf *fdf)
{
	int x;
	int y;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
		{
			map->rot[y][x].x = fdf->mas[y][x].world.x;
			map->rot[y][x].y = fdf->mas[y][x].world.y;
			map->rot[y][x].z = fdf->mas[y][x].world.z;
		}
	}
}

static void	get_corners(t_fdf *fdf, double mtx[4][4])
{
	t_3d tmp;

	ft_bzero(&tmp, sizeof(tmp));
	tmp.x = fdf->map->bas[0][0].x;
	tmp.y = fdf->map->bas[0][0].y;
	vec_mult_matrix(&tmp, mtx, &fdf->corner[0]);
	ft_bzero(&tmp, sizeof(tmp));
	tmp.x = fdf->map->bas[0][fdf->map->cols - 1].x;
	tmp.y = fdf->map->bas[0][fdf->map->cols - 1].y;
	vec_mult_matrix(&tmp, mtx, &fdf->corner[1]);
	ft_bzero(&tmp, sizeof(tmp));
	tmp.x = fdf->map->bas[fdf->map->rows - 1][0].x;
	tmp.y = fdf->map->bas[fdf->map->rows - 1][0].y;
	vec_mult_matrix(&tmp, mtx, &fdf->corner[2]);
	ft_bzero(&tmp, sizeof(tmp));
	tmp.x = fdf->map->bas[fdf->map->rows - 1][fdf->map->cols - 1].x;
	tmp.y = fdf->map->bas[fdf->map->rows - 1][fdf->map->cols - 1].y;
	vec_mult_matrix(&tmp, mtx, &fdf->corner[3]);
}

static void	threads_computing(t_fdf *fdf)
{
	void *result;

	pthread_create(&fdf->t[0], NULL, draw_map, fdf);
	pthread_create(&fdf->t[1], NULL, draw_map, fdf);
	pthread_create(&fdf->t[2], NULL, draw_map, fdf);
	pthread_create(&fdf->t[3], NULL, draw_map, fdf);
	pthread_join(fdf->t[0], &result);
	pthread_join(fdf->t[1], &result);
	pthread_join(fdf->t[2], &result);
	pthread_join(fdf->t[3], &result);
}

static void	start_trasformation(t_fdf *fdf)
{
	double mtx_glob[4][4];

	matrix_identity(mtx_glob);
	tr_translate(mtx_glob, -(fdf->map->cols - 1) / 2,
			-(fdf->map->rows - 1) / 2,
			-(fdf->map->max_z + fdf->map->min_z) / 2);
	tr_scale(mtx_glob, fdf->param.s_all, fdf->param.s_all,
			fdf->param.s_all);
	tr_rotate(mtx_glob, fdf->param.rx, fdf->param.ry, fdf->param.rz);
	get_projection(fdf, mtx_glob);
	tr_translate(mtx_glob, fdf->w_size.x / 2,
			fdf->w_size.y / 2, 0);
	tr_translate(mtx_glob, fdf->param.tx, fdf->param.ty,
			fdf->param.tz);
	mult_local_by_glob_mtx(fdf->mas, fdf->map, mtx_glob);
	get_corners(fdf, mtx_glob);
	init_res_map(fdf->map, fdf);
}

void		do_operations(t_fdf *fdf)
{
	ft_bzero(fdf->img.img, fdf->img.size_line * fdf->w_size.y);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	start_trasformation(fdf);
	threads_computing(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	if (fdf->param.help)
	{
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->help.img_ptr,
								0, 0);
		get_help(fdf);
	}
}
