#include "fdf.h"

static void	cabine(double matrix[4][4])
{
	static double	mtx_c[4][4] = {
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
	};
	double			mtx_tmp[4][4];

	mtx_c[2][0] = -0.5 * cos(45 * M_PI / 180);
	mtx_c[2][1] = 0.5 * sin(45 * M_PI / 180);
	matrix_mult(matrix, mtx_c, mtx_tmp);
	matrix_copy(mtx_tmp, matrix);
}

static void	cavalie(double matrix[4][4])
{
	static double	mtx_c[4][4] = {
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
	};
	double			mtx_tmp[4][4];

	mtx_c[2][0] = -1 * cos(45 * M_PI / 180);
	mtx_c[2][1] = 1 * sin(45 * M_PI / 180);
	matrix_mult(matrix, mtx_c, mtx_tmp);
	matrix_copy(mtx_tmp, matrix);
}

void	get_projection(t_fdf *fdf, double mtx[4][4])
{
	if (fdf->projection == CAVALIE)
		cavalie(mtx);
	else if (fdf->projection == CABINE)
		cabine(mtx);
	else if (fdf->projection == TRIMETRIC)
		tr_rotate2(mtx, -45 * M_PI / 180, 30 * M_PI / 180);
	else if (fdf->projection == DIMETRIC)
		tr_rotate2(mtx, -26.23 * M_PI / 180, 29.52 * M_PI / 180);
	else if (fdf->projection == ISOMETRIC)
		tr_rotate2(mtx, -35.26 * M_PI / 180, 45 * M_PI / 180);

}