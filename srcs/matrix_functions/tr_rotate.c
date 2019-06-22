#include "graphic.h"
#include "libft.h"
#include "math.h"
#define SIN(x) tab->sin_table[ABS((int)x&255)]
#define COS(x) tab->cos_table[ABS((int)x&255)]

static void		rot_x(t_table *tab, double mtx1[4][4], double mtx2[4][4],
		int dx)
{
	static double	mtx_x[4][4] = {
			{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}
	};

	mtx_x[1][1] = COS(dx);
	mtx_x[1][2] = SIN(dx);
	mtx_x[2][1] = -SIN(dx);
	mtx_x[2][2] = COS(dx);
	matrix_mult(mtx1, mtx_x, mtx2);
}

static void		rot_y(t_table *tab, double mtx1[4][4], double mtx2[4][4],
		int dy)
{
	static double	mtx_y[4][4] = {
			{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}
	};

	mtx_y[0][0] = COS(dy);
	mtx_y[0][2] = -SIN(dy);
	mtx_y[2][0] = SIN(dy);
	mtx_y[2][2] = COS(dy);
	matrix_mult(mtx1, mtx_y, mtx2);
}

static void		rot_z(t_table *tab, double mtx1[4][4], double mtx2[4][4],
		int dz)
{
	static double mtx_z[4][4] = {
			{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}
	};

	mtx_z[0][0] = COS(dz);
	mtx_z[0][1] = SIN(dz);
	mtx_z[1][0] = -SIN(dz);
	mtx_z[1][1] = COS(dz);
	matrix_mult(mtx1, mtx_z, mtx2);
}

static t_table	*init_trig_table(void)
{
	int				i;
	t_table			*t;

	t = (t_table*)ft_memalloc(sizeof(t_table));
	i = -1;
	while (++i < 256)
	{
		t->sin_table[i] = sin(i * M_PI / 128.0);
		t->cos_table[i] = cos(i * M_PI / 128.0);
	}
	return (t);
}

void			tr_rotate(double matrix[4][4], int dx, int dy, int dz)
{
	static t_table	*table = NULL;
	double			mtx_tmp1[4][4];
	double			mtx_tmp2[4][4];

	if (table == NULL)
		table = init_trig_table();
	rot_y(table, matrix, mtx_tmp1, dy);
	rot_x(table, mtx_tmp1, mtx_tmp2, dx);
	rot_z(table, mtx_tmp2, matrix, dz);
}



















