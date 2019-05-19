#include "fdf.h"
#include "mlx.h"

void	init_values(t_point *delta, t_point *sign, t_point *a, t_point *b)
{
	delta->x = ABS(b->x - a->x);
	delta->y = ABS(b->y - a->y);
	sign->x = a->x < b->x ? 1 : -1;
	sign->y = a->y < b->y ? 1 : -1;
}

void	draw_line(t_point *a, t_point *b, t_fdf *fdf, int color)
{
	t_point	delta;
	t_point sign;
	int		error;
	int		error2;

	init_values(&delta, &sign, a, b);
	error = delta.x - delta.y;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, b->x, b->y, color);
	while(a->x != b->x || a->y != b->y)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, a->x, a->y, color);
		error2 = error * 2;
		if(error2 > -delta.y)
		{
			error -= delta.y;
			a->x += sign.x;
		}
		if(error2 < delta.x)
		{
			error += delta.x;
			a->y += sign.y;
		}
	}
}