/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:55:44 by vuslysty          #+#    #+#             */
/*   Updated: 2019/07/12 16:55:45 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void		init_help(t_fdf *fdf)
{
	int		i;

	fdf->help.img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->w_size.x,
			fdf->w_size.y);
	fdf->help.img = mlx_get_data_addr(fdf->help.img_ptr,
			&fdf->help.bits_per_pixel, &fdf->help.size_line, &fdf->help.endian);
	fdf->help.frame = (int**)ft_memalloc(sizeof(int*) * fdf->w_size.y);
	i = -1;
	while (++i < fdf->w_size.y)
		fdf->help.frame[i] = (int*)(fdf->help.img + (fdf->help.size_line * i));
	paint_rainbow(fdf);
}

static void	init_window_and_image(t_fdf *fdf)
{
	int		i;

	fdf->w_size.x = 2000;
	fdf->w_size.y = 1200;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->w_size.x,
			fdf->w_size.y, "FDF");
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->w_size.x,
			fdf->w_size.y);
	fdf->img.img = mlx_get_data_addr(fdf->img.img_ptr,
			&fdf->img.bits_per_pixel, &fdf->img.size_line, &fdf->img.endian);
	fdf->img.frame = (int**)ft_memalloc(sizeof(int*) * fdf->w_size.y);
	i = -1;
	while (++i < fdf->w_size.y)
		fdf->img.frame[i] = (int*)(fdf->img.img + (fdf->img.size_line * i));
	init_help(fdf);
}

void		first_init(char *filename, t_fdf *fdf)
{
	int		i;

	ft_bzero(fdf, sizeof(t_fdf));
	fdf->map = (t_map*)ft_memalloc(sizeof(t_map));
	fdf->map->min_z = INT32_MAX;
	fdf->map->max_z = INT32_MIN;
	read_fdf_map(filename, fdf->map);
	if (!fdf->map->color)
		add_color_to_white_map(fdf->map);
	fdf->param.s_all < 1 ? fdf->param.s_all = 1 : 0;
	fdf->map->rot = get_copy_base_map(fdf->map);
	init_window_and_image(fdf);
	fdf->param.s_all = ((fdf->w_size.y / (fdf->map->rows > fdf->map->cols ?
			fdf->map->rows : fdf->map->cols)) - 1);
	fdf->mas = (t_vertex**)ft_memalloc(sizeof(t_vertex*) * fdf->map->rows);
	i = -1;
	while (++i < fdf->map->rows)
		fdf->mas[i] = (t_vertex*)ft_memalloc(sizeof(t_vertex) * fdf->map->cols);
	init_mas_local(fdf->mas, fdf->map);
	fdf->projection = ORTO;
}

static void	set_projection(int kcode, t_fdf *fdf)
{
	if (kcode == 31)
		fdf->projection = ORTO;
	else if (kcode == 8)
		fdf->projection = CAVALIE;
	else if (kcode == 40)
		fdf->projection = CABINE;
	else if (kcode == 17)
		fdf->projection = TRIMETRIC;
	else if (kcode == 2)
		fdf->projection = DIMETRIC;
	else if (kcode == 34)
		fdf->projection = ISOMETRIC;
}

void		set_param(int kcode, t_fdf *fdf)
{
	if (kcode == 89 || kcode == 92)
		fdf->param.rx += kcode == 89 ? -2 : 2;
	else if (kcode == 86 || kcode == 88)
		fdf->param.ry += kcode == 86 ? -2 : 2;
	else if (kcode == 83 || kcode == 85)
		fdf->param.rz += kcode == 83 ? -2 : 2;
	else if (kcode == 123 || kcode == 124)
		fdf->param.tx += kcode == 123 ? -15 : 15;
	else if (kcode == 125 || kcode == 126)
		fdf->param.ty += kcode == 125 ? 15 : -15;
	else if (kcode == 78 && fdf->param.s_all > 0)
		fdf->param.s_all -= 0.5;
	else if (kcode == 69 && fdf->param.s_all < 1000)
		fdf->param.s_all += 0.5;
	else if (kcode == 122)
		fdf->param.color = 0;
	else if (kcode == 120)
		fdf->param.color = 1;
	else if (kcode == 3)
		fdf->param.fps = fdf->param.fps == 1 ? 0 : 1;
	else if (kcode == 53)
		close_fdf((void*)0);
	else if (kcode == 4)
		fdf->param.help = fdf->param.help == 1 ? 0 : 1;
	set_projection(kcode, fdf);
}
