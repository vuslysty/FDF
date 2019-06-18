#ifndef FDF_GRAPHIC_H
#define FDF_GRAPHIC_H

typedef int t_out_code;

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
	struct s_3d		aligned;
}					t_vertex;

typedef struct		s_table
{
	double			sin_table[256];
	double			cos_table[256];
}					t_table;

typedef struct		s_poligon_2d
{
	struct s_2d		points[20];
	int				points_count;
	int				texture;
}					t_poligon_2d;

typedef struct		s_polygon
{
	int 			count;
	int				*vertex;
	int 			texture;
	struct s_vertex	p;
	struct s_vertex	m;
	struct s_vertex	n;
}					t_polygon;

typedef struct		s_object
{
	int				vertex_count;
	int 			polygon_count;
	struct s_vertex	*vertex;
	struct s_polygon	*polygon;
	struct s_3d			scaling;
	struct s_3d			position;
	struct s_3d			angle;
	int					need_update;
}					t_object;


void	matrix_copy(double src[4][4], double dst[4][4]);
void	matrix_mult(double mtx1[4][4], double mtx2[4][4], double dst[4][4]);
void	vec_mult_matrix(t_3d *src, double mtx[4][4], t_3d *dst);
void	tr_rotate(double matrix[4][4], int dx, int dy, int dz);
//void	tr_rotate(double matrix[4][4], int dx, int dy, int dz, int kcode);
void	matrix_identity(double mtx[4][4]);
void	tr_translate(double matrix[4][4], double tx, double ty, double tz);
void	tr_scale(double matrix[4][4], double sx, double sy, double sz);



#endif //FDF_GRAPHIC_H
