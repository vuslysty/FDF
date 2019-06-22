#include "validator.h"
#include "libft.h"
#include "mlx.h" // man /usr/share/man/man3/
#include "fdf.h"
#include "math.h"
#define L_UP 	fdf->corner[0].z
#define L_DOWN	fdf->corner[2].z
#define R_UP 	fdf->corner[1].z
#define R_DOWN 	fdf->corner[3].z

void	init_res_map(t_map *map, t_fdf *fdf)
{
	int x;
	int y;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
		{
		  	map->rot[y][x].x = fdf->mas[y][x].world.x;
			map->rot[y][x].y = fdf->mas[y][x].world.y;
			map->rot[y][x].z = fdf->mas[y][x].world.z;
		}
	}
}

void	get_corners(t_fdf *fdf, double mtx[4][4])
{
	t_3d tmp;

	ft_bzero(&tmp, sizeof(tmp));
	tmp.x = fdf->map->bas[0][0].x;
	tmp.y = fdf->map->bas[0][0].y;
	vec_mult_matrix(&tmp, mtx, &fdf->corner[0]);
	ft_bzero(&tmp, sizeof(tmp));
	tmp.x = fdf->map->bas[0][fdf->map->cols - 1].x;
	tmp.y = fdf->map->bas[0][fdf->map->cols - 1].y;
	vec_mult_matrix(&tmp, mtx, &fdf->corner[1]);
	ft_bzero(&tmp, sizeof(tmp));
	tmp.x = fdf->map->bas[fdf->map->rows - 1][0].x;
	tmp.y = fdf->map->bas[fdf->map->rows - 1][0].y;
	vec_mult_matrix(&tmp, mtx, &fdf->corner[2]);
	ft_bzero(&tmp, sizeof(tmp));
	tmp.x = fdf->map->bas[fdf->map->rows - 1][fdf->map->cols - 1].x;
	tmp.y = fdf->map->bas[fdf->map->rows - 1][fdf->map->cols - 1].y;
	vec_mult_matrix(&tmp, mtx, &fdf->corner[3]);
}

void	set_projection(int kcode, t_fdf *fdf)
{
	if (kcode == 31)
		fdf->projection = ORTO;
	else if (kcode == 8)
		fdf->projection = CAVALIE;
	else if (kcode == 40)
		fdf->projection = CABINE;
	else if (kcode == 17)
		fdf->projection = TRIMETRIC;
	else if (kcode == 2)
		fdf->projection = DIMETRIC;
	else if (kcode == 34)
		fdf->projection = ISOMETRIC;
}

void	set_param(int kcode, t_fdf *fdf)
{
	if (kcode == 89 || kcode == 92)
		fdf->param.rx += kcode == 89 ? -2 : 2;
	else if (kcode == 86 || kcode == 88)
		fdf->param.ry += kcode == 86 ? -2 : 2;
	else if (kcode == 83 || kcode == 85)
		fdf->param.rz += kcode == 83 ? -2 : 2;
	else if (kcode == 123 || kcode == 124)
		fdf->param.tx += kcode == 123 ? -15 : 15;
	else if (kcode == 125 || kcode == 126)
		fdf->param.ty += kcode == 125 ? 15 : -15;
	else if (kcode == 27 && fdf->param.s_all > 0)
		fdf->param.s_all -= 0.5;
	else if (kcode == 24 && fdf->param.s_all < 1000)
		fdf->param.s_all += 0.5;
	else if (kcode == 122)
		fdf->param.color = 0;
	else if (kcode == 120)
		fdf->param.color = 1;
	else if (kcode == 3)
		fdf->param.fps = fdf->param.fps == 1 ? 0 : 1;
	set_projection(kcode, fdf);
}

void	threads_computing(t_fdf *fdf)
{
	void *result;

	pthread_create(&fdf->t[0], NULL, draw_map, fdf);
	pthread_create(&fdf->t[1], NULL, draw_map, fdf);
	pthread_create(&fdf->t[2], NULL, draw_map, fdf);
	pthread_create(&fdf->t[3], NULL, draw_map, fdf);
	pthread_join(fdf->t[0], &result);
	pthread_join(fdf->t[1], &result);
	pthread_join(fdf->t[2], &result);
	pthread_join(fdf->t[3], &result);
}

void	start_trasformation(t_fdf *fdf)
{
	double mtx_glob[4][4];

	matrix_identity(mtx_glob);
	tr_translate(mtx_glob, -(fdf->map->cols - 1) / 2,
			-(fdf->map->rows - 1) / 2,
			-(fdf->map->max_z + fdf->map->min_z) / 2);
	tr_scale(mtx_glob, fdf->param.s_all, fdf->param.s_all,
			fdf->param.s_all);
	tr_rotate(mtx_glob, fdf->param.rx, fdf->param.ry, fdf->param.rz);
	get_projection(fdf, mtx_glob);
	tr_translate(mtx_glob, fdf->w_size.x / 2,
				 fdf->w_size.y / 2, 0);
	tr_translate(mtx_glob, fdf->param.tx, fdf->param.ty,
				 fdf->param.tz);
	mult_local_by_glob_mtx(fdf->mas, fdf->map, mtx_glob);
	get_corners(fdf, mtx_glob);
	init_res_map(fdf->map, fdf);
}

int		key_hook(int kcode, void *data)
{
	t_fdf			*fdf;
	t_fps			fps;

	fdf = (t_fdf*)data;
	start_fps(&fps, fdf);
	set_param(kcode, fdf);
	start_trasformation(fdf);
	threads_computing(fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	ft_bzero(fdf->img.img, fdf->img.size_line * fdf->w_size.y);
	end_fps(&fps, fdf);
	return (0);
}


void	add_color_to_white_map(t_map *map)
{
	t_2d p;
	t_point start;
	t_point end;
	t_point curr;
	t_point delta;

	start.x = map->min_z;
	start.y = 0;
	start.color = 0x00ff00;
	end.x = map->max_z;
	end.y = 0;
	end.color = 0xff0000;
	delta.x = map->max_z - map->min_z;
	delta.y = 0;
	curr.y = 0;
	p.y = -1;
	while (++p.y < map->rows)
	{
		p.x = -1;
		while (++p.x < map->cols)
		{
			curr.x = map->bas[p.y][p.x].z;
			map->bas[p.y][p.x].color = get_color(curr, start, end, delta);
		}
	}
}

void	init_window_and_image(t_fdf *fdf)
{
	int i;

	fdf->w_size.x = 2000;
	fdf->w_size.y = 1200;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->w_size.x,
								 fdf->w_size.y, "FDF");
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->w_size.x,
			fdf->w_size.y);
	fdf->img.img = mlx_get_data_addr (fdf->img.img_ptr,
			&fdf->img.bits_per_pixel, &fdf->img.size_line, &fdf->img.endian);
	fdf->img.frame = (int**)ft_memalloc(sizeof(int*) * fdf->w_size.y);
	i = -1;
	while (++i < fdf->w_size.y)
		fdf->img.frame[i] = (int*)(fdf->img.img + (fdf->img.size_line * i));
}

void	first_init(char *filename, t_fdf *fdf)
{
	int 	i;

	ft_bzero(fdf, sizeof(t_fdf));
	fdf->map = (t_map*)ft_memalloc(sizeof(t_map));
	fdf->map->min_z = INT32_MAX;
	fdf->map->max_z = INT32_MIN;
	read_fdf_map(filename, fdf->map);
	if (!fdf->map->color)
		add_color_to_white_map(fdf->map);
	fdf->param.s_all = 1;
	fdf->map->rot = get_copy_base_map(fdf->map);
	init_window_and_image(fdf);
	fdf->mas = (t_vertex**)ft_memalloc(sizeof(t_vertex*) * fdf->map->rows);
	i = -1;
	while (++i < fdf->map->rows)
		fdf->mas[i] = (t_vertex*)ft_memalloc(sizeof(t_vertex) * fdf->map->cols);
	init_mas_local(fdf->mas, fdf->map);
	fdf->projection = ORTO;
}

int main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		ft_error("usage:  ./fdf [filename]\n");
	first_init(argv[1], &fdf);
	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}





























