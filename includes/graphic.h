#ifndef FDF_GRAPHIC_H
#define FDF_GRAPHIC_H

typedef int			t_out_code;

typedef struct		s_ln_clipping
{
	t_out_code		code0;
	t_out_code		code1;
	t_out_code		out;
	double			x;
	double			y;
	int 			accept;
}					t_clipping;

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

typedef struct		s_vertex
{
	struct s_3d		local;
	struct s_3d		world;
}					t_vertex;

typedef struct		s_table
{
	double			sin_table[256];
	double			cos_table[256];
}					t_table;

void				matrix_copy(double src[4][4], double dst[4][4]);
void				matrix_mult(double mtx1[4][4], double mtx2[4][4],
		double dst[4][4]);
void				vec_mult_matrix(t_3d *src, double mtx[4][4], t_3d *dst);
void				tr_rotate(double matrix[4][4], int dx, int dy, int dz);
void				tr_rotate2(double matrix[4][4], double dx, double dy);
void				matrix_identity(double mtx[4][4]);
void				tr_translate(double matrix[4][4], double tx, double ty,
		double tz);
void				tr_scale(double matrix[4][4], double sx, double sy,
		double sz);
void				cavalie(double matrix[4][4]);

#endif