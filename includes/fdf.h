//
// Created by Vladyslav USLYSTYI on 2019-03-20.
//

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include "libft.h"

typedef struct		s_point
{
	int 			x;
	int 			y;
}					t_point;

typedef struct		s_fdf
{
	struct s_map	*map;
	struct s_point	point;
	struct s_point	windows_size;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_fdf;

typedef struct		s_map
{
	int				**map;
	int 			cols;
	int 			rows;
}					t_map;

void	draw_line(t_point *a, t_point *b, t_fdf *fdf, int color);
int		is_delimiter(char c);
void	del_list_content(void *content, size_t tmp);
void	read_fdf_map(char *file, t_map *map);


#endif //FDF_FDF_H
