#include "validator.h"
#include "libft.h"
#include "mlx.h" // man /usr/share/man/man3/
#include "fdf.h"
#include "math.h"


//void	fill_poligons(t_fdf *fdf)
//{
//	int i = 0;
//	int x, y;
//
//	y = -1;
//	while (++y < fdf->map->rows - 1)
//	{
//		x = -1;
//		while (++x < fdf->map->cols - 1)
//		{
//			fdf->poligon[i].points[0].x = fdf->mas[y][x].world.x;
//			fdf->poligon[i].points[0].y = fdf->mas[y][x].world.y;
//
//			fdf->poligon[i].points[1].x = fdf->mas[y + 1][x].world.x;
//			fdf->poligon[i].points[1].y = fdf->mas[y + 1][x].world.y;
//
//			fdf->poligon[i].points[2].x = fdf->mas[y + 1][x + 1].world.x;
//			fdf->poligon[i].points[2].y = fdf->mas[y + 1][x + 1].world.y;
//
//			fdf->poligon[i].points[3].x = fdf->mas[y][x + 1].world.x;
//			fdf->poligon[i].points[3].y = fdf->mas[y][x + 1].world.y;
//
//			fdf->poligon[i++].points_count = 4;
//		}
//	}
//}
//
//
//int main()
//{
//	t_fdf	fdf;
//
//	fdf.w_size.x = 2000;
//	fdf.w_size.y = 1200;
//
//	fdf.mlx_ptr = mlx_init();
//	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.w_size.x,
//								 fdf.w_size.y, "mlx 42");
//
//	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, fdf.w_size.x, fdf.w_size.y);
//
//	char *img;
//
//	int bits_per_pixel;
//	int size_line;
//	int endian;
//
//	img = mlx_get_data_addr (fdf.img_ptr, &bits_per_pixel, &size_line, &endian);
//
//	int **frame = (int**)ft_memalloc(sizeof(int*) * fdf.w_size.y);
//
//	int i = -1;
//	while (++i < fdf.w_size.y)
//		frame[i] = (img + (size_line * i));
//
//	fdf.frame = frame;
//	fdf.img = img;
///////////////////////////////////////
//
//	fdf.pol_count = (fdf.w_size.x - 1) * (fdf.w_size.y - 1);
//	fdf.poligon = (t_poligon_2d*)ft_memalloc(sizeof(t_poligon_2d) * fdf.pol_count);
//
///////////////////////////////////////
//	mlx_loop(fdf.mlx_ptr);
//	return (0);
//}