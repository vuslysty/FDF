//
// Created by Vladyslav USLYSTYI on 2019-03-20.
//

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "libft.h"
# include "math.h"

typedef struct			s_point
{
	int 				x;
	int 				y;
	int					z;
	int 				color;
}						t_point;

typedef struct			s_fdf
{
	struct s_matrixes	*matrixes;
	struct s_transform_p *param;
	struct s_map		*map;
	struct s_point		w_size;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int 				**frame;
	char 				*img;
}						t_fdf;

typedef struct			s_map
{
	struct s_point		**rot;
	struct s_point		**bas;
	int 				cols;
	int 				rows;
	int 				deep;
}						t_map;

typedef struct			s_matrix
{
	double				**mtx;
	int 				rows;
	int 				cols;
}						t_matrix;

typedef struct			s_matrixes
{
	struct s_matrix		*rot_x;
	struct s_matrix 	*rot_y;
	struct s_matrix		*rot_z;
	struct s_matrix		*translate;
	struct s_matrix 	*scale;
	struct s_matrix 	*partica_scale;
	struct s_matrix 	*shift;
	struct s_matrix 	*one;

	struct s_matrix 	*base;
	struct s_matrix 	*result_point;
}						t_matrixes;

typedef struct			s_transform_p
{
	int					tx;
	int 				ty;
	int 				tz;
	int 				sx;
	int 				sy;
	int 				sz;
	double				s_all;
	int 				shx;
	int 				shy;
	int 				shz;
	double				rx;
	double				ry;
	double				rz;
}						t_transform_p;

void		draw_line(t_point *a, t_point *b, t_fdf *fdf, int color);
int			is_delimiter(char c);
void		del_list_content(void *content, size_t tmp);
void		read_fdf_map(char *file, t_map *map);
int			get_color(t_point current, t_point start, t_point end, t_point delta);
void		draw_gradient_line(t_point *a, t_point *b, t_fdf *fdf, t_point curr);
t_point		**get_copy_base_map(t_map *map);
t_matrix	*mult_matrixes(t_matrix *m1, t_matrix *m2);
void		*mult_matrixes_arg(t_matrix *m1, t_matrix *m2, t_matrix *m3);

void	init_partical_scale(t_matrixes *matrixes, t_transform_p *p);
void	init_scale(t_matrixes *matrixes, t_transform_p *p);
void	init_rot_x(t_matrixes *matrixes, t_transform_p *p);
void	init_rot_y(t_matrixes *matrixes, t_transform_p *p);
void	init_rot_z(t_matrixes *matrixes, t_transform_p *p);
void	init_translate(t_matrixes *matrixes, t_transform_p *p);

void	init_one(t_matrixes *matrixes, t_transform_p *p);
void	init_base(t_matrixes *matrixes, t_transform_p *p);

void	init_matrixes(t_matrixes *matrixes, t_transform_p *param);

void	first_init_matrixes(t_matrixes *matrixes);
int put_pixel(t_fdf *fdf, int x, int y, int color);


#endif
