#include "fdf.h"

void	init_rot_x(t_matrixes *matrixes, t_transform_p *p)
{
	t_matrix	*matrix;

	matrix = matrixes->rot_x;
	matrix->mtx[0][0] = 1;
	matrix->mtx[0][1] = 0;
	matrix->mtx[0][2] = 0;
	matrix->mtx[0][3] = 0;
	matrix->mtx[1][0] = 0;
	matrix->mtx[1][1] = cos(p->rx);
	matrix->mtx[1][2] = sin(p->rx);
	matrix->mtx[1][3] = 0;
	matrix->mtx[2][0] = 0;
	matrix->mtx[2][1] = -sin(p->rx);
	matrix->mtx[2][2] = cos(p->rx);
	matrix->mtx[2][3] = 0;
	matrix->mtx[3][0] = 0;
	matrix->mtx[3][1] = 0;
	matrix->mtx[3][2] = 0;
	matrix->mtx[3][3] = 1;
}

void	init_rot_y(t_matrixes *matrixes, t_transform_p *p)
{
	t_matrix	*matrix;

	matrix = matrixes->rot_y;
	matrix->mtx[0][0] = cos(p->ry);
	matrix->mtx[0][1] = 0;
	matrix->mtx[0][2] = -sin(p->ry);
	matrix->mtx[0][3] = 0;
	matrix->mtx[1][0] = 0;
	matrix->mtx[1][1] = 1;
	matrix->mtx[1][2] = 0;
	matrix->mtx[1][3] = 0;
	matrix->mtx[2][0] = sin(p->ry);
	matrix->mtx[2][1] = 0;
	matrix->mtx[2][2] = cos(p->ry);
	matrix->mtx[2][3] = 0;
	matrix->mtx[3][0] = 0;
	matrix->mtx[3][1] = 0;
	matrix->mtx[3][2] = 0;
	matrix->mtx[3][3] = 1;
}

void	init_rot_z(t_matrixes *matrixes, t_transform_p *p)
{
	t_matrix	*matrix;

	matrix = matrixes->rot_z;
	matrix->mtx[0][0] = cos(p->rz);
	matrix->mtx[0][1] = sin(p->rz);
	matrix->mtx[0][2] = 0;
	matrix->mtx[0][3] = 0;
	matrix->mtx[1][0] = -sin(p->rz);
	matrix->mtx[1][1] = cos(p->rz);
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

void	init_translate(t_matrixes *matrixes, t_transform_p *p)
{
	t_matrix	*matrix;

	matrix = matrixes->translate;
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
	matrix->mtx[3][0] = p->tx;
	matrix->mtx[3][1] = p->ty;
	matrix->mtx[3][2] = p->tz;
	matrix->mtx[3][3] = 1;
}

//void	init_shift(t_matrixes *matrixes, t_transform_p *p)
//{
//	t_matrix	*matrix;
//
//	matrix = matrixes->translate;
//	matrix->mtx[0][0] = 1;
//	matrix->mtx[0][1] = 0;
//	matrix->mtx[0][2] = 0;
//	matrix->mtx[0][3] = 0;
//	matrix->mtx[1][0] = 0;
//	matrix->mtx[1][1] = 1;
//	matrix->mtx[1][2] = 0;
//	matrix->mtx[1][3] = 0;
//	matrix->mtx[2][0] = 0;
//	matrix->mtx[2][1] = 0;
//	matrix->mtx[2][2] = 1;
//	matrix->mtx[2][3] = 0;
//	matrix->mtx[3][0] = p->tx;
//	matrix->mtx[3][1] = p->ty;
//	matrix->mtx[3][2] = p->tz;
//	matrix->mtx[3][3] = 1;
//}