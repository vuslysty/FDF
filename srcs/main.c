#include "validator.h"
#include "libft.h"
#include "mlx.h" // man /usr/share/man/man3/
#include "fdf.h"
#include "math.h"

void	rot_x(double deg, t_map *map)
{
	int x;
	int y;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->rows)
		{
			map->rot[y][x].x = (map->bas[y][x].x);
			map->rot[y][x].y = (map->bas[y][x].y * cos(deg) + map->bas[y][x].z * sin(deg));
			map->rot[y][x].z = (-map->bas[y][x].y * sin(deg) + map->bas[y][x].z * cos(deg));
		}
	}
}

void	rot_y(double deg, t_map *map)
{
	int x;
	int y;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->rows)
		{
			map->rot[y][x].x = (map->rot[y][x].x * cos(deg) + map->rot[y][x].z * sin(deg));
			map->rot[y][x].y = (map->rot[y][x].y);
			map->rot[y][x].z = (-map->rot[y][x].x * sin(deg) + map->rot[y][x].z * cos(deg));
		}
	}
}

void	rot_z(double deg, t_map *map)
{
	int x;
	int y;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->rows)
		{
			map->rot[y][x].x = (map->rot[y][x].x * cos(deg) - map->rot[y][x].y * sin(deg));
			map->rot[y][x].y = (map->rot[y][x].x * sin(deg) + map->rot[y][x].y * cos(deg));
			map->rot[y][x].z = map->rot[y][x].z;
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
	static double	deg_x = 0;
	static double	deg_y = 0;
	static double	deg_z = 0;

	fdf = (t_fdf*)data;
	if (kcode == 89)
		deg_x -= 0.0174533;
	if (kcode == 92)
		deg_x += 0.0174533;
	if (kcode == 86)
		deg_y -= 0.0174533;
	if (kcode == 88)
		deg_y += 0.0174533;
	if (kcode == 83)
		deg_z -= 0.0174533;
	if (kcode == 85)
		deg_z += 0.0174533;

	rot_x(deg_x, fdf->map);
	rot_y(deg_y, fdf->map);
	rot_z(deg_z, fdf->map);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_map(fdf, fdf->map);
	return (0);
}

int main()
{
//	t_fdf	fdf;
//
//	fdf.windows_size.x = 2000;
//	fdf.windows_size.y = 1200;
//
//	t_point a = {100, 100};
//	t_point b = {2000, 210};
//
//	fdf.mlx_ptr = mlx_init();
//	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.windows_size.x,
//			fdf.windows_size.y, "mlx 42");
////	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);
//	draw_line(&a, &b, &fdf, 234234);
//	mlx_loop(fdf.mlx_ptr);

	t_map	map;

	read_fdf_map("elem-fract.fdf", &map);

	int y;
	int x;

	y = -1;
	while (++y < map.rows)
	{
		x = -1;
		while (++x < map.cols)
		{
			map.bas[y][x].x += 400;
			map.bas[y][x].y += 400;
		}
	}

//	int i = -1, j;
//	while (++i < map.rows)
//	{
//		j = -1;
//		while (++j < map.cols)
//			ft_printf("%i,%#x ", map.map[i][j].z, map.map[i][j].color);
//		ft_printf("\n");
//	}
//	system("leaks -q FDF");

	t_fdf	fdf;

	fdf.map = &map;
	map.rot = get_copy_base_map(fdf.map);

//	y = -1;
//	while (++y < map.rows)
//	{
//		x = -1;
//		while (++x < map.cols)
//			ft_printf("%i ", fdf.map->rot[y][x].x);
//		ft_printf("\n");
//	}

	fdf.windows_size.x = 2000;
	fdf.windows_size.y = 1200;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.windows_size.x,
			fdf.windows_size.y, "mlx 42");
	draw_map(&fdf, &map);
	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);

	return (0);
}

// 359 degrees = 6,26573 radian
// 1   degrees = 0,0174533 rad