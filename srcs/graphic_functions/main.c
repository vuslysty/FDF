#include "validator.h"
#include "libft.h"
#include "mlx.h" // man /usr/share/man/man3/
#include "fdf.h"
#include "math.h"

int main()
{
//	t_fdf	fdf;

	fdf.w_size.x = 2000;
	fdf.w_size.y = 1200;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.w_size.x,
								 fdf.w_size.y, "mlx 42");

	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, fdf.w_size.x, fdf.w_size.y);

	char *img;

	int bits_per_pixel;
	int size_line;
	int endian;

	img = mlx_get_data_addr (fdf.img_ptr, &bits_per_pixel, &size_line, &endian);

	int **frame = (int**)ft_memalloc(sizeof(int*) * fdf.w_size.y);

	int i = -1;
	while (++i < fdf.w_size.y)
		frame[i] = (img + (size_line * i));

	fdf.frame = frame;
	fdf.img = img;
/////////////////////////////////////

	t_poligon_2d	poligon;

	poligon.points[0].x = 0;
	poligon.points[0].y = 0;

	poligon.points[1].x = 0;
	poligon.points[1].y = 500;

	poligon.points[2].x = 100;
	poligon.points[2].y = 500;

	poligon.points[3].x = 100;
	poligon.points[3].y = 0;

//	poligon.points[4].x = 100;
//	poligon.points[4].y = 400;
//
//	poligon.points[5].x = 100;
//	poligon.points[5].y = 0;

	poligon.points_count = 4;

	polygon_draw(&poligon);

	poligon.points[0].x = 100;
	poligon.points[0].y = 500;

	poligon.points[1].x = 100;
	poligon.points[1].y = 400;

	poligon.points[2].x = 400;
	poligon.points[2].y = 500;

	poligon.points[3].x = 500;
	poligon.points[3].y = 500;

	polygon_draw(&poligon);

	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img_ptr, 0, 0);

/////////////////////////////////////
	mlx_loop(fdf.mlx_ptr);
	return (0);
}