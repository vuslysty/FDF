//
// Created by Vladyslav USLYSTYI on 2019-03-20.
//

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "libft.h"
# include "math.h"
# include "graphic.h"
#include <pthread.h>

enum e_projection
		{
			ORTO, CAVALIE, CABINE, TRIMETRIC, DIMETRIC, ISOMETRIC
		};

typedef struct			s_point
{
	int 				x;
	int 				y;
	int					z;
	int 				color;
}						t_point;

typedef struct			s_mthread
{
	int 				d;
	int					count;
	int					thread_index;
	pthread_t			curr_thread;
}						t_mthread;

typedef struct			s_dline
{
	struct s_point		a;
	struct s_point		b;
	struct s_dline		*next;
}						t_dline;

typedef struct			s_transform_p
{
	int 				color;
	double				tx;
	double 				ty;
	double 				tz;
	double 				sx;
	double 				sy;
	double 				sz;
	double				s_all;
	int				rx;
	int				ry;
	int				rz;
}						t_transform_p;

typedef struct			s_fdf
{
	pthread_t 			t[4];
	enum e_projection	projection;
	struct s_3d			corner[4];
	struct s_transform_p param;
	struct s_map		*map;
	struct s_point		w_size;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int 				**frame;
	char 				*img;
	struct s_vertex		**mas;
}						t_fdf;

typedef struct			s_map
{
	struct s_point		**rot;
	struct s_point		**bas;
	int 				cols;
	int 				rows;
	int					min_z;
	int					max_z;
	int 				color;
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

void	*draw_map(void *param);
void	draw_line_3d(t_3d a, t_3d b, t_fdf *fdf, int color);
void		draw_line(t_point a, t_point b, t_fdf *fdf, int color);
int			is_delimiter(char c);
void		del_list_content(void *content, size_t tmp);
void		read_fdf_map(char *file, t_map *map);
int			get_color(t_point current, t_point start, t_point end, t_point delta);
void		draw_gradient_line(t_point *a, t_point *b, t_fdf *fdf, t_point curr);
void	draw_white_line(t_point *a, t_point *b, t_fdf *fdf, t_point curr);
void	draw_color_line(t_point *a, t_point *b, t_fdf *fdf, t_point curr);
t_point		**get_copy_base_map(t_map *map);
t_matrix	*mult_matrixes(t_matrix *m1, t_matrix *m2, int opt);
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




void	init_mas_local(struct s_vertex **mas, t_map *map);
void	mult_local_by_glob_mtx(struct s_vertex **mas, t_map *map, double global[4][4]);
void	mult_world_by_glob_mtx(struct s_vertex **mas, t_map *map, double global[4][4]);

void	mult_local_by_glob_mtx_for_local(struct s_vertex **mas, t_map *map, double global[4][4]);

void	line_clip_and_draw(t_point a, t_point b, t_fdf *fdf);
//void	line_clip_and_draw(t_point *a, t_point *b, t_fdf *fdf);
//void	draw_gradient_line(t_point a, t_point b, t_fdf *fdf, t_point curr);

void	polygon_draw(t_poligon_2d *polygon, struct s_fdf *fdf);

void	add_new_line(t_dline **list, t_point *a, t_point *b);
void	del_dline_list(t_dline **list);

void	get_projection(t_fdf *fdf, double mtx[4][4]);

#endif
