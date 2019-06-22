#include "graphic.h"
#include "libft.h"
#include "math.h"

static void		rot_x(double mtx1[4][4], double mtx2[4][4], double dx)
{
	static double	mtx_x[4][4] = {
			{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}
	};

	mtx_x[1][1] = cos(dx);
	mtx_x[1][2] = sin(dx);
	mtx_x[2][1] = -sin(dx);
	mtx_x[2][2] = cos(dx);
	matrix_mult(mtx1, mtx_x, mtx2);
}

static void		rot_y(double mtx1[4][4], double mtx2[4][4], double dy)
{
	static double	mtx_y[4][4] = {
			{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}
	};

	mtx_y[0][0] = cos(dy);
	mtx_y[0][2] = -sin(dy);
	mtx_y[2][0] = sin(dy);
	mtx_y[2][2] = cos(dy);
	matrix_mult(mtx1, mtx_y, mtx2);
}

void			tr_rotate2(double matrix[4][4], double dx, double dy)
{
	double			mtx_tmp1[4][4];

	rot_y(matrix, mtx_tmp1, dy);
	rot_x(mtx_tmp1, matrix, dx);
}