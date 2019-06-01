#include "fdf.h"

void	init_partical_scale(t_matrixes *matrixes, t_transform_p *p)
{
	t_matrix	*matrix;

	matrix = matrixes->partica_scale;
	matrix->mtx[0][0] = p->sx;
	matrix->mtx[0][1] = 0;
	matrix->mtx[0][2] = 0;
	matrix->mtx[0][3] = 0;
	matrix->mtx[1][0] = 0;
	matrix->mtx[1][1] = p->sy;
	matrix->mtx[1][2] = 0;
	matrix->mtx[1][3] = 0;
	matrix->mtx[2][0] = 0;
	matrix->mtx[2][1] = 0;
	matrix->mtx[2][2] = p->sz;
	matrix->mtx[2][3] = 0;
	matrix->mtx[3][0] = 0;
	matrix->mtx[3][1] = 0;
	matrix->mtx[3][2] = 0;
	matrix->mtx[3][3] = 1;
}

void	init_scale(t_matrixes *matrixes, t_transform_p *p)
{
	t_matrix	*matrix;

	matrix = matrixes->scale;
	matrix->mtx[0][0] = 1;
	matrix->mtx[0][1] = 0;
	matrix->mtx[0][2] = 0;
	matrix->mtx[0][3] = 0;
	matrix->mtx[1][0] = 0;
	matrix->mtx[1][1] = 1;
	matrix->mtx[1][2] = 0;
	matrix->mtx[1][3] = 0;
	matrix->mtx[2][0] = 0;
	matrix->mtx[2][1] = 0;
	matrix->mtx[2][2] = 1;
	matrix->mtx[2][3] = 0;
	matrix->mtx[3][0] = 0;
	matrix->mtx[3][1] = 0;
	matrix->mtx[3][2] = 0;
	matrix->mtx[3][3] = p->s_all;
}

void	init_base(t_matrixes *matrixes, t_transform_p *p)
{
	t_matrix	*matrix;

	matrix = matrixes->base;
	matrix->mtx[0][0] = 1;
	matrix->mtx[0][1] = 0;
	matrix->mtx[0][2] = 0;
	matrix->mtx[0][3] = 0;
	matrix->mtx[1][0] = 0;
	matrix->mtx[1][1] = 1;
	matrix->mtx[1][2] = 0;
	matrix->mtx[1][3] = 0;
	matrix->mtx[2][0] = 0;
	matrix->mtx[2][1] = 0;
	matrix->mtx[2][2] = 1;
	matrix->mtx[2][3] = 0;
	matrix->mtx[3][0] = 0;
	matrix->mtx[3][1] = 0;
	matrix->mtx[3][2] = 0;
	matrix->mtx[3][3] = 1;
}

void	init_one(t_matrixes *matrixes, t_transform_p *p)
{
	t_matrix	*matrix;

	matrix = matrixes->one;
	matrix->mtx[0][0] = 1;
	matrix->mtx[0][1] = 0;
	matrix->mtx[0][2] = 0;
	matrix->mtx[0][3] = 0;
	matrix->mtx[1][0] = 0;
	matrix->mtx[1][1] = 1;
	matrix->mtx[1][2] = 0;
	matrix->mtx[1][3] = 0;
	matrix->mtx[2][0] = 0;
	matrix->mtx[2][1] = 0;
	matrix->mtx[2][2] = 1;
	matrix->mtx[2][3] = 0;
	matrix->mtx[3][0] = 0;
	matrix->mtx[3][1] = 0;
	matrix->mtx[3][2] = 0;
	matrix->mtx[3][3] = 1;
}