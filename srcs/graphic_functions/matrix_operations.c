#include "graphic.h"
# define SIN(x) sin_table[ABS((int)x&255)]
# define COS(x) cos_table[ABS((int)x&255)]

void	matrix_copy(double src[4][4], double dst[4][4])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			dst[i][j] = src[i][j];
	}
}

void	matrix_mult(double mtx1[4][4], double mtx2[4][4], double dst[4][4])
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			dst[i][j] = 0;
			k = -1;
			while (++k < 4)
				dst[i][j] += mtx1[i][k] * mtx2[k][j];
		}
	}
}

void	vec_mult_matrix(t_3d *src, double mtx[4][4], t_3d *dst)
{
	dst->x = src->x * mtx[0][0] +
			src->y * mtx[1][0] +
			src->z * mtx[2][0] + mtx[3][0];
	dst->x = src->x * mtx[0][1] +
			src->y * mtx[1][1] +
			src->z * mtx[2][1] + mtx[3][1];
	dst->x = src->x * mtx[0][2] +
			src->y * mtx[1][2] +
			src->z * mtx[2][2] + mtx[3][2];
}

