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

int		close_fdf(void *param)
{
	(void)param;
	exit(0);
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
	else if (kcode == 53)
		close_fdf((void*)0);
	else if (kcode == 4)
		fdf->param.help = fdf->param.help == 1 ? 0 : 1;
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

void	get_help(t_fdf *fdf)
{
	static char	*help =
			"ROTATE:\n"
   "x-asix  -  7 | 9\n"
   "y-asix  -  4 | 6\n"
   "x-asix  -  1 | 3\n";

	
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 0x00FF00, help);
}

void	do_operations(t_fdf *fdf)
{
	ft_bzero(fdf->img.img, fdf->img.size_line * fdf->w_size.y);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	start_trasformation(fdf);
	threads_computing(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img_ptr, 0, 0);
	if (fdf->param.help)
	{
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->help.img_ptr,
								0, 0);
		get_help(fdf);
	}
}

int		key_hook(int kcode, void *data)
{
	t_fdf			*fdf;
	t_fps			fps;

	fdf = (t_fdf*)data;
	start_fps(&fps, fdf);
	set_param(kcode, fdf);
	do_operations(fdf);
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

void	init_help(t_fdf *fdf)
{
	int i;

	fdf->help.img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->w_size.x,
									 fdf->w_size.y);
	fdf->help.img = mlx_get_data_addr (fdf->help.img_ptr,
									  &fdf->help.bits_per_pixel, &fdf->help.size_line, &fdf->help.endian);
	fdf->help.frame = (int**)ft_memalloc(sizeof(int*) * fdf->w_size.y);
	i = -1;
	while (++i < fdf->w_size.y)
		fdf->help.frame[i] = (int*)(fdf->help.img + (fdf->help.size_line * i));

	t_point rainbow[8];

	rainbow[0].x = 0;
	rainbow[0].y = 0;
	rainbow[0].color = 0x00ff0000;

	rainbow[1].x = 285;
	rainbow[1].y = 0;
	rainbow[1].color = 0x00ffdd00;

	rainbow[2].x = 570;
	rainbow[2].y = 0;
	rainbow[2].color = 0x0021ff00;

	rainbow[3].x = 855;
	rainbow[3].y = 0;
	rainbow[3].color = 0x0000fffa;

	rainbow[4].x = 1140;
	rainbow[4].y = 0;
	rainbow[4].color = 0x00000cff;

	rainbow[5].x = 1425;
	rainbow[5].y = 0;
	rainbow[5].color = 0x00c300ff;

	rainbow[6].x = 1710;
	rainbow[6].y = 0;
	rainbow[6].color = 0x00c300ff;

	rainbow[7].x = 1999;
	rainbow[7].y = 0;
	rainbow[7].color = 0x00ff0000;




	int y = -1;
	while (++y < fdf->w_size.y)
	{
		draw_gradient_line_h(rainbow[0], rainbow[1], fdf, rainbow[0]);
		draw_gradient_line_h(rainbow[1], rainbow[2], fdf, rainbow[0]);
		draw_gradient_line_h(rainbow[2], rainbow[3], fdf, rainbow[0]);
		draw_gradient_line_h(rainbow[3], rainbow[4], fdf, rainbow[0]);
		draw_gradient_line_h(rainbow[4], rainbow[5], fdf, rainbow[0]);
		draw_gradient_line_h(rainbow[5], rainbow[6], fdf, rainbow[0]);
		draw_gradient_line_h(rainbow[6], rainbow[7], fdf, rainbow[0]);

		rainbow[0].y++;
		rainbow[1].y++;
		rainbow[2].y++;
		rainbow[3].y++;
		rainbow[4].y++;
		rainbow[5].y++;
		rainbow[6].y++;
		rainbow[7].y++;
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
	init_help(fdf);
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
	mlx_hook(fdf.win_ptr, 17, 0, close_fdf, &fdf);

	mlx_loop(fdf.mlx_ptr);
	return (0);
}





























