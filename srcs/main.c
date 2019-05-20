#include "validator.h"
#include "libft.h"
#include "mlx.h" // man /usr/share/man/man3/
#include "fdf.h"

int		key_hook(int kcode, void *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)data;
	if (kcode == 123 && fdf->point.x > 0)
		fdf->point.x--;
	if (kcode == 124 && fdf->point.x < fdf->windows_size.x)
		fdf->point.x++;
	if (kcode == 126 && fdf->point.y > 0)
		fdf->point.y--;
	if (kcode == 125 && fdf->point.y < fdf->windows_size.y)
		fdf->point.y++;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->point.x, fdf->point.y, 624235);
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
//	t_point b = {1000, 1200};
//
//	fdf.mlx_ptr = mlx_init();
//	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.windows_size.x,
//			fdf.windows_size.y, "mlx 42");
////	mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, 555, 555, 624235);
////	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);
//	draw_line(&a, &b, &fdf, 234234);
//	mlx_loop(fdf.mlx_ptr);

	t_map	map;

	read_fdf_map("mars.fdf", &map);

	int i = -1, j;
	while (++i < map.rows)
	{
		j = -1;
		while (++j < map.cols)
			ft_printf("%i ", map.map[i][j]);
		ft_printf("\n");
	}
	system("leaks -q FDF");
	return (0);
}