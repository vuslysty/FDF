//
// Created by Vladyslav USLYSTYI on 2019-03-20.
//

#ifndef FDF_FDF_H
#define FDF_FDF_H

typedef struct		s_point
{
	int 			x;
	int 			y;
}					t_point;

typedef struct		s_fdf
{
	struct s_point	point;
	struct s_point	windows_size;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_fdf;

#endif //FDF_FDF_H
