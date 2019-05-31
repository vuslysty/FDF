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
			fdf->matrixes->result_point->mtx[0][0] = map->bas[y][x].x;
			fdf->matrixes->result_point->mtx[0][1] = map->bas[y][x].y;
			fdf->matrixes->result_point->mtx[0][2] = map->bas[y][x].z;
			fdf->matrixes->result_point->mtx[0][3] = 1;

			fdf->matrixes->result_point = mult_matrixes(fdf->matrixes->result_point, fdf->matrixes->result_matrix);

			map->bas[y][x].x = fdf->matrixes->result_point->mtx[0][0];
			map->bas[y][x].y = fdf->matrixes->result_point->mtx[0][1];
			map->bas[y][x].z = fdf->matrixes->result_point->mtx[0][2];

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
				draw_gradient_line(&map->rot[y][x], &map->rot[y][x + 1], fdf, map->rot[y][x]);
			if (y != map->rows - 1)
				draw_gradient_line(&map->rot[y][x], &map->rot[y + 1][x], fdf, map->rot[y][x]);
		}
	}
}

int		key_hook(int kcode, void *data)
{
	t_fdf			*fdf;

	fdf = (t_fdf*)data;
	if (kcode == 89)
		fdf->param->rx = 0.0174533;
	if (kcode == 92)
		fdf->param->rx = 0.0174533;
	if (kcode == 86)
		fdf->param->ry -= 0.0174533;
	if (kcode == 88)
		fdf->param->ry += 0.0174533;
	if (kcode == 83)
		fdf->param->rz -= 0.0174533;
	if (kcode == 85)
		fdf->param->rz += 0.0174533;

//	fdf->param->tx = fdf->w_size.x / 2;
//	fdf->param->ty = fdf->w_size.y / 2;
//	fdf->param->tz;

	fdf->param->tx = 0;
	fdf->param->ty = 0;

	int c = 50;
	fdf->param->sx = c;
	fdf->param->sy = c;
	fdf->param->sz = c;

	fdf->param->tx -= fdf->map->rows * c / 2;
	fdf->param->ty -= fdf->map->cols * c / 2;

	init_matrixes(fdf->matrixes, fdf->param);

	fdf->matrixes->result_matrix = mult_matrixes(fdf->matrixes->one, fdf->matrixes->partica_scale);
	fdf->matrixes->result_matrix = mult_matrixes(fdf->matrixes->result_matrix, fdf->matrixes->translate);

	fdf->matrixes->result_matrix = mult_matrixes(fdf->matrixes->result_matrix, fdf->matrixes->rot_x);
	fdf->matrixes->result_matrix = mult_matrixes(fdf->matrixes->result_matrix, fdf->matrixes->rot_y);
	fdf->matrixes->result_matrix = mult_matrixes(fdf->matrixes->result_matrix, fdf->matrixes->rot_z);
//	fdf->matrixes->result_matrix = mult_matrixes(fdf->matrixes->result_matrix, fdf->matrixes->partica_scale);

	fdf->param->tx += fdf->map->rows * c / 2;
	fdf->param->ty += fdf->map->cols * c / 2;

	fdf->param->tx += fdf->w_size.x / 2;
	fdf->param->ty += fdf->w_size.y / 2;

	init_matrixes(fdf->matrixes, fdf->param);
//
	fdf->matrixes->result_matrix = mult_matrixes(fdf->matrixes->result_matrix, fdf->matrixes->translate);

	rotate(fdf->map, fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_map(fdf, fdf->map);
	return (0);
}

int main()
{
	t_fdf	fdf;

	fdf.map = (t_map*)ft_memalloc(sizeof(t_map));
	read_fdf_map("elem.fdf", fdf.map);

	fdf.matrixes = (t_matrixes*)ft_memalloc(sizeof(t_matrixes));
	fdf.param = (t_transform_p*)ft_memalloc(sizeof(t_transform_p));

	first_init_matrixes(fdf.matrixes);

	fdf.map->rot = get_copy_base_map(fdf.map);

//	y = -1;
//	while (++y < map.rows)
//	{
//		x = -1;
//		while (++x < map.cols)
//			ft_printf("%i ", fdf.map->rot[y][x].x);
//		ft_printf("\n");
//	}

	fdf.w_size.x = 2000;
	fdf.w_size.y = 1200;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.w_size.x,
			fdf.w_size.y, "mlx 42");
	draw_map(&fdf, fdf.map);
	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);

	return (0);
}

// 359 degrees = 6,26573 radian
// 1   degrees = 0,0174533 rad