#include "validator.h"
#include "libft.h"
#include "mlx.h" // man /usr/share/man/man3/
#include "fdf.h"
#include "math.h"

void	rotate(t_map *map, t_fdf *fdf)
{
	int x;
	int y;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->rows)
		{
			fdf->matrixes->result_point->mtx[0][0] = map->bas[y][x].x * fdf->param->s_all;
			fdf->matrixes->result_point->mtx[0][1] = map->bas[y][x].y * fdf->param->s_all;
			fdf->matrixes->result_point->mtx[0][2] = map->bas[y][x].z * fdf->param->s_all;
			fdf->matrixes->result_point->mtx[0][3] = 1;

			fdf->matrixes->result_point = mult_matrixes(fdf->matrixes->result_point, fdf->matrixes->base, 1);

			map->rot[y][x].x = fdf->matrixes->result_point->mtx[0][0];
			map->rot[y][x].y = fdf->matrixes->result_point->mtx[0][1];
			map->rot[y][x].z = fdf->matrixes->result_point->mtx[0][2];

//			map->rot[y][x].x = (map->bas[y][x].x - map->cols / 2 * 5) * cos(dy) * cos(dz) +
//					(map->bas[y][x].y - (map->rows / 2) * 5) * (sin(dx) * sin(dy) * cos(dz) + cos(dx) * sin(dz)) +
//					map->bas[y][x].z * (-cos(dx) * sin(dy) * cos(dz) + sin(dx) * sin(dz));
//			map->rot[y][x].y = -(map->bas[y][x].x - map->cols / 2 * 5) * cos(dy) * sin(dz) +
//					(map->bas[y][x].y - (map->rows / 2) * 5) * (-sin(dx) * sin(dy) * sin(dz) + cos(dx) * cos(dz)) +
//					map->bas[y][x].z * (cos(dx) * sin(dy) * sin(dz) + sin(dx) * cos(dz));
//			map->rot[y][x].z = (map->bas[y][x].x - map->cols / 2 * 5) * sin(dy) -
//					(map->bas[y][x].y - (map->rows / 2) * 5) * sin(dx) * cos(dy) +
//					map->bas[y][x].z * cos(dx) * cos(dy);
//			map->rot[y][x].x = map->rot[y][x].x + fdf->w_size.x / 2;
//			map->rot[y][x].y = map->rot[y][x].y + fdf->w_size.y / 2;

		}
	}
}

void	draw_map(t_fdf *fdf, t_map *map)
{
	int y;
	int x;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
		{
				if (x != map->cols - 1)
				{
					draw_gradient_line(&map->rot[y][x], &map->rot[y][x + 1], fdf,
									   map->rot[y][x]);
					if (y != 0)
						draw_gradient_line(&map->rot[y][x], &map->rot[y - 1][x + 1], fdf,
										   map->rot[y][x]);
					if (y != map->rows - 1)
						draw_gradient_line(&map->rot[y][x], &map->rot[y + 1][x + 1], fdf,
										   map->rot[y][x]);
				}
				if (y != map->rows - 1)
				{
					draw_gradient_line(&map->rot[y][x], &map->rot[y + 1][x], fdf,
									   map->rot[y][x]);
				}

		}
	}
}


int		key_hook(int kcode, void *data)
{
	t_fdf			*fdf;

	double deg = 0.0474533;

	fdf = (t_fdf*)data;
	if (kcode == 89 || kcode == 92)
		fdf->param->rx += kcode == 89 ? -deg : deg;
	else if (kcode == 86 || kcode == 88)
		fdf->param->ry += kcode == 86 ? -deg : deg;
	else if (kcode == 83 || kcode == 85)
		fdf->param->rz += kcode == 83 ? -deg : deg;
//	else if (kcode == 123 || kcode == 124)
//		fdf->param->tx += kcode == 123 ? -5 : 5;
//	else if (kcode == 125 || kcode == 126)
//		fdf->param->ty += kcode == 125 ? 5 : -5;
//
	if (kcode == 27 || kcode == 24)
		fdf->param->s_all += kcode == 27 ? -1 : 1;

	fdf->param->tx = -(fdf->map->rows - 1) * (fdf->param->s_all / 2);
	fdf->param->ty = -(fdf->map->cols - 1) * (fdf->param->s_all / 2);

	init_matrixes(fdf->matrixes, fdf->param);

	fdf->matrixes->base = mult_matrixes(fdf->matrixes->one, fdf->matrixes->translate, 0);

	fdf->matrixes->base = mult_matrixes(fdf->matrixes->base,
											fdf->matrixes->rot_x, 1);
	fdf->matrixes->base = mult_matrixes(fdf->matrixes->base,
											fdf->matrixes->rot_y, 1);
	fdf->matrixes->base = mult_matrixes(fdf->matrixes->base,
											fdf->matrixes->rot_z, 1);
//
	fdf->param->tx += (fdf->map->rows - 1) * (fdf->param->s_all / 2);
	fdf->param->ty += (fdf->map->cols - 1) * (fdf->param->s_all / 2);

	fdf->param->tx += fdf->w_size.x / 2.0;
	fdf->param->ty += fdf->w_size.y / 2.0;
//
//
//
	init_translate(fdf->matrixes, fdf->param);
	fdf->matrixes->base = mult_matrixes(fdf->matrixes->base, fdf->matrixes->translate, 1);

	rotate(fdf->map, fdf);

	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_map(fdf, fdf->map);

//	put_pixel(fdf, 10, fdf->param->s_all, 0xffffff);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	ft_bzero(fdf->img, 8000 * fdf->w_size.y);

	return (0);
}

int main()
{
	t_fdf	fdf;
//
	fdf.map = (t_map*)ft_memalloc(sizeof(t_map));
	read_fdf_map("test_maps/mars.fdf", fdf.map);

	int i = -1;
	while (++i < fdf.map->rows)
	{
		int j = -1;
		while (++j < fdf.map->cols)
			ft_printf("%i ", fdf.map->bas[i][j].y);
		ft_printf("\n");
	}



//
	fdf.matrixes = (t_matrixes*)ft_memalloc(sizeof(t_matrixes));
	fdf.param = (t_transform_p*)ft_memalloc(sizeof(t_transform_p));

	first_init_matrixes(fdf.matrixes);
	init_base(fdf.matrixes, fdf.param);

	fdf.param->s_all = 1;

//	fdf.param->tx -= fdf.map->rows / 2;
//	fdf.param->ty -= fdf.map->cols / 2;

//	init_translate(fdf.matrixes, fdf.param);
//	fdf.matrixes->base = mult_matrixes(fdf.matrixes->base, fdf.matrixes->translate);

	fdf.map->rot = get_copy_base_map(fdf.map);
//

//
	fdf.w_size.x = 2000;
	fdf.w_size.y = 1200;
//
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.w_size.x,
			fdf.w_size.y, "mlx 42");
//	draw_map(&fdf, fdf.map);
//	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);
//
//
//	mlx_loop(fdf.mlx_ptr);

	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, fdf.w_size.x, fdf.w_size.y);

	char *img;

	int bits_per_pixel;
	int size_line;
	int endian;

	img = mlx_get_data_addr (fdf.img_ptr, &bits_per_pixel, &size_line, &endian);


	int **frame = (int**)ft_memalloc(sizeof(int*) * fdf.w_size.y);

//	int i = -1;
	i = -1;
	while (++i < fdf.w_size.y)
		frame[i] = (img + (size_line * i));

	fdf.frame = frame;
	fdf.img = img;

	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);


	mlx_loop(fdf.mlx_ptr);


	return (0);
}

// 359 degrees = 6,26573 radian
// 1   degrees = 0,0174533 rad





























