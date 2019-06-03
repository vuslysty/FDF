#include "graphic.h"

void	matrix_identity(double mtx[4][4])
{
	mtx[0][0] = 1;
	mtx[0][1] = 0;
	mtx[0][2] = 0;
	mtx[0][3] = 0;
	mtx[1][0] = 0;
	mtx[1][1] = 1;
	mtx[1][2] = 0;
	mtx[1][3] = 0;
	mtx[2][0] = 0;
	mtx[2][1] = 0;
	mtx[2][2] = 1;
	mtx[2][3] = 0;
	mtx[3][0] = 0;
	mtx[3][1] = 0;
	mtx[3][2] = 0;
	mtx[3][3] = 1;
}

void	tr_translate(double matrix[4][4], double tx, double ty, double tz)
{
	static double	mtx_t[4][4] = {
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
	};
	double			mtx_tmp[4][4];

	mtx_t[3][0] = tx;
	mtx_t[3][1] = ty;
	mtx_t[3][2] = tz;
	matrix_mult(matrix, mtx_t, mtx_tmp);
	matrix_copy(mtx_tmp, matrix);
}

void	tr_scale(double matrix[4][4], double sx, double sy, double sz)
{
	static double	mtx_s[4][4] = {
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
	};
	double			mtx_tmp[4][4];

	mtx_s[1][1] = sx;
	mtx_s[2][2] = sy;
	mtx_s[3][3] = sz;
	matrix_mult(matrix, mtx_s, mtx_tmp);
	matrix_copy(mtx_tmp, matrix);
}
