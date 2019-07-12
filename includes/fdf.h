/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:14:41 by vuslysty          #+#    #+#             */
/*   Updated: 2019/07/12 17:14:58 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "libft.h"
# include "math.h"
# include "graphic.h"
# include <pthread.h>

enum					e_projection {
	ORTO, CAVALIE, CABINE, TRIMETRIC, DIMETRIC, ISOMETRIC
};

typedef struct			s_fps
{
	struct timeval		t0;
	struct timeval		t1;
	float				diff;
}						t_fps;

struct					s_image
{
	void				*img_ptr;
	int					**frame;
	char				*img;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
};

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

/*
** d - diagonal for draw line algorithm
*/

typedef struct			s_mthread
{
	int					d;
	int					count;
	int					thread_index;
	pthread_t			curr_thread;
}						t_mthread;

struct					s_param
{
	int					help;
	int					fps;
	int					color;
	double				tx;
	double				ty;
	double				tz;
	double				s_all;
	int					rx;
	int					ry;
	int					rz;
};

typedef struct			s_fdf
{
	struct s_image		help;
	struct s_image		img;
	pthread_t			t[4];
	enum e_projection	projection;
	struct s_3d			corner[4];
	struct s_param		param;
	struct s_map		*map;
	struct s_point		w_size;
	void				*mlx_ptr;
	void				*win_ptr;
	struct s_vertex		**mas;
}						t_fdf;

typedef struct			s_map
{
	struct s_point		**rot;
	struct s_point		**bas;
	int					cols;
	int					rows;
	int					min_z;
	int					max_z;
	int					color;
}						t_map;

void					*draw_map(void *param);
int						is_delimiter(char c);
void					del_list_content(void *content, size_t tmp);
void					read_fdf_map(char *file, t_map *map);
int						get_color(t_point current, t_point start, t_point end,
		t_point delta);
void					draw_gradient_line(t_point *a, t_point *b, t_fdf *fdf,
		t_point curr);
void					draw_gradient_line_h(t_point a, t_point b, t_fdf *fdf,
		t_point curr);
void					draw_white_line(t_point *a, t_point *b, t_fdf *fdf,
		t_point curr);
void					draw_color_line(t_point *a, t_point *b, t_fdf *fdf,
		t_point curr);
t_point					**get_copy_base_map(t_map *map);
void					init_mas_local(struct s_vertex **mas, t_map *map);
void					mult_local_by_glob_mtx(struct s_vertex **mas,
		t_map *map, double global[4][4]);
void					line_clip_and_draw(t_point a, t_point b, t_fdf *fdf);
void					get_projection(t_fdf *fdf, double mtx[4][4]);
void					start_fps(t_fps *fps, t_fdf *fdf);
void					end_fps(t_fps *fps, t_fdf *fdf);

void					paint_rainbow(t_fdf *fdf);
void					do_operations(t_fdf *fdf);
void					init_help(t_fdf *fdf);
void					add_color_to_white_map(t_map *map);
void					set_param(int kcode, t_fdf *fdf);
int						close_fdf(void *param);
void					first_init(char *filename, t_fdf *fdf);

void					fps_instructions(t_fdf *fdf);
void					color_instructions(t_fdf *fdf);
void					projection_instructions(t_fdf *fdf);
void					rotate_instructions(t_fdf *fdf);
void					scale_instructions(t_fdf *fdf);
void					get_help(t_fdf *fdf);

#endif
