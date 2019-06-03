#ifndef FDF_GRAPHIC_H
#define FDF_GRAPHIC_H

typedef struct		s_2d
{
	int 			x;
	int 			y;
}					t_2d;

typedef struct		s_3d
{
	double 			x;
	double 			y;
	double 			z;
}					t_3d;

typedef struct		t_vertex
{
	struct s_3d		local;
	struct s_3d		world;
	struct s_3d		aligned;
}					t_vertex;

typedef struct		s_table
{
	double			sin_table[256];
	double			cos_table[256];
}					t_table;

void	matrix_copy(double src[4][4], double dst[4][4]);
void	matrix_mult(double mtx1[4][4], double mtx2[4][4], double dst[4][4]);
void	vec_mult_matrix(t_3d *src, double mtx[4][4], t_3d *dst);

#endif //FDF_GRAPHIC_H
