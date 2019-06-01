#include "fdf.h"

int put_pixel(t_fdf *fdf, int x, int y, int color)
{
	fdf->frame[y][x] = color;
}
