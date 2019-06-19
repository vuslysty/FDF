#include "validator.h"
#include "libft.h"
#include "mlx.h" // man /usr/share/man/man3/
#include "fdf.h"
#include "math.h"

#define L_UP 	fdf->corner[0].z
#define L_DOWN	fdf->corner[2].z
#define R_UP 	fdf->corner[1].z
#define R_DOWN 	fdf->corner[3].z

#define FOCAL_DISTANCE 200

//void	fill_poligons(t_fdf *fdf)
//{
//	int i = 0;
//	int x, y;
//
//	y = -1;
//	while (++y < fdf->map->rows - 1)
//	{
//		x = -1;
//		while (++x < fdf->map->cols - 1)
//		{
//			fdf->poligon[i].points[0].x = fdf->mas[y][x].world.x;
//			fdf->poligon[i].points[0].y = fdf->mas[y][x].world.y;
//
//			fdf->poligon[i].points[1].x = fdf->mas[y + 1][x].world.x;
//			fdf->poligon[i].points[1].y = fdf->mas[y + 1][x].world.y;
//
//			fdf->poligon[i].points[2].x = fdf->mas[y + 1][x + 1].world.x;
//			fdf->poligon[i].points[2].y = fdf->mas[y + 1][x + 1].world.y;
//
//			fdf->poligon[i].points[3].x = fdf->mas[y][x + 1].world.x;
//			fdf->poligon[i].points[3].y = fdf->mas[y][x + 1].world.y;
//
//			fdf->poligon[i].texture =
////					fdf->map->bas[y][x].color;
//
////			ft_printf("%x ", fdf->poligon[i].texture);
//
//					(((fdf->map->bas[y][x].color >> 16) +
//					(fdf->map->bas[y + 1][x].color >> 16) +
//					(fdf->map->bas[y][x + 1].color >> 16) +
//					(fdf->map->bas[y + 1][x + 1].color >> 16) / 4) << 16) |
//
//					(((fdf->map->bas[y][x].color >> 8 & 0xff) +
//					(fdf->map->bas[y + 1][x].color >> 8 & 0xff) +
//					(fdf->map->bas[y][x + 1].color >> 8 & 0xff) +
//					(fdf->map->bas[y + 1][x + 1].color >> 8 & 0xff) / 4) << 8) |
//
//					(((fdf->map->bas[y][x].color & 0xff) +
//					(fdf->map->bas[y + 1][x].color & 0xff) +
//					(fdf->map->bas[y][x + 1].color & 0xff) +
//					(fdf->map->bas[y + 1][x + 1].color & 0xff)) / 4);
//
//			fdf->poligon[i++].points_count = 4;
//		}
////		ft_printf("\n");
//	}
////	ft_printf("\n");
//}

void	rotate(t_map *map, t_fdf *fdf)
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

//			map->rot[y][x].x = fdf->mas[y][x].aligned.x;
//			map->rot[y][x].y = fdf->mas[y][x].aligned.y;
//			map->rot[y][x].z = fdf->mas[y][x].aligned.z;
//
//
//
//			if(fdf->mas[y][x].aligned.z == 0)
//				fdf->mas[y][x].aligned.z = 1;
//			map->rot[y][x].x = FOCAL_DISTANCE * fdf->mas[y][x].aligned.x / fdf->mas[y][x].aligned.z + fdf->w_size.x / 2;
//			map->rot[y][x].y = FOCAL_DISTANCE * fdf->mas[y][x].aligned.y / fdf->mas[y][x].aligned.z + fdf->w_size.y / 2;

		}
	}
}

void	draw_map2(t_fdf *fdf, t_map *map)
{
	int y;
	int x;
	int d;

	d = 0;

	if (L_UP <= L_DOWN && L_UP <= R_DOWN && L_UP <= R_UP)
		while (d < map->cols + map->rows)
		{
			x = d;
			y = 0;
			while (x >= 0 && y < map->rows)
			{
				if (x < map->cols && y < map->rows)
				{
					if (x != map->cols - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1], fdf);
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x], fdf);
				}
				x--;
				y++;
			}
			d++;
		}
	else if (R_UP <= L_UP && R_UP <= R_DOWN && R_UP <= L_DOWN)
	{
		while (d < map->cols + map->rows)
		{
			x = map->cols - 1 - d;
			y = 0;
			while (x < map->cols && y < map->rows)
			{
				if (x >= 0 && y < map->rows)
				{
					if (x != 0)
						line_clip_and_draw(map->rot[y][x], map->rot[y][x - 1], fdf);
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x], fdf);
				}
				x++;
				y++;
			}
			d++;
		}
	}
	else if (L_DOWN <= L_UP && L_DOWN <= R_DOWN && L_DOWN <= R_UP)
	{
		while (d < map->cols + map->rows)
		{
			x = d;
			y = map->rows - 1;
			while (x >= 0 && y >= 0)
			{
				if (x < map->cols && y < map->rows)
				{
					if (x != map->cols - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1], fdf);
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x], fdf);
				}
				x--;
				y--;
			}
			d++;
		}
	}
	else
	{
		while (d < map->cols + map->rows)
		{
			x = map->cols - 1 - d;
			y = map->rows - 1;
			while (x < map->cols && y >= 0)
			{
				if (x >= 0 && y < map->rows)
				{
					if (x != map->cols - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1], fdf);
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x], fdf);
				}
				x++;
				y--;
			}
			d++;
		}
	}

}


void	draw_map(t_fdf *fdf, t_map *map)
{
	int y;
	int x;


	if (L_UP <= L_DOWN && L_UP <= R_DOWN && L_UP <= R_UP)
	{
		if (R_UP < L_DOWN)
		{
			y = -1;
			while (++y < map->rows)
			{
				x = -1;
				while (++x < map->cols)
				{
					if (x != map->cols - 1)
					{
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1],
										   fdf);
//						if (y != 0)
//							line_clip_and_draw(map->rot[y][x], map->rot[y - 1][x + 1], fdf);
//						if (y != map->rows - 1)
//							line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x + 1], fdf);
					}
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x],
										   fdf);
				}
			}
		}
		else
		{
			x = -1;
			while (++x < map->cols)
			{
				y = -1;
				while (++y < map->rows)
				{
					if (x != map->cols - 1)
					{
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1],
										   fdf);
//						if (y != 0)
//							line_clip_and_draw(map->rot[y][x],
//											   map->rot[y - 1][x + 1], fdf);
//						if (y != map->rows - 1)
//							line_clip_and_draw(map->rot[y][x],
//											   map->rot[y + 1][x + 1], fdf);
					}
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x],
										   fdf);
				}
			}
		}
	}





	else if (L_DOWN <= L_UP && L_DOWN <= R_DOWN && L_DOWN <= R_UP)
	{
		if (L_UP < R_DOWN)
		{
			x = -1;
			while (++x < map->cols)
			{
				y = map->rows;
				while (--y >= 0)
				{
					if (x != map->cols - 1)
					{
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1],
										   fdf);
//						if (y != 0)
//							line_clip_and_draw(map->rot[y][x], map->rot[y - 1][x + 1], fdf);
//						if (y != map->rows - 1)
//							line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x + 1], fdf);
					}
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x],
										   fdf);
				}
			}
		}
		else
		{
			y = map->rows;
			while (--y >= 0)
			{
				x = -1;
				while (++x < map->cols)
				{
					if (x != map->cols - 1)
					{
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1],
										   fdf);
//						if (y != 0)
//							line_clip_and_draw(map->rot[y][x], map->rot[y - 1][x + 1], fdf);
//						if (y != map->rows - 1)
//							line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x + 1], fdf);
					}
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x],
										   fdf);
				}
			}
		}
	}

	else if (R_UP <= L_UP && R_UP <= R_DOWN && R_UP <= L_DOWN)
	{
		if (L_UP < R_DOWN)
		{
			y = -1;
			while (++y < map->rows)
			{
				x = map->cols;
				while (--x >= 0)
				{
					if (x != map->cols - 1)
					{
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1],
										   fdf);
//						if (y != 0)
//							line_clip_and_draw(map->rot[y][x], map->rot[y - 1][x + 1], fdf);
//						if (y != map->rows - 1)
//							line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x + 1], fdf);
					}
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x],
										   fdf);
				}
			}
		}
		else
		{
			x = map->cols;
			while (--x >= 0)
			{
				y = -1;
				while (++y < map->rows)
				{
					if (x != map->cols - 1)
					{
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1],
										   fdf);
//						if (y != 0)
//							line_clip_and_draw(map->rot[y][x], map->rot[y - 1][x + 1], fdf);
//						if (y != map->rows - 1)
//							line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x + 1], fdf);
					}

					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x],
										   fdf);
				}
			}
		}
	}

//	if (R_DOWN <= L_UP && R_DOWN <= R_UP && R_DOWN <= L_DOWN)
	else
	{
		if (L_DOWN < R_UP)
		{
			y = map->rows;
			while (--y >= 0)
			{
				x = map->cols;
				while (--x >= 0)
				{
					if (x != map->cols - 1)
					{
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1],
										   fdf);
//						if (y != 0)
//							line_clip_and_draw(map->rot[y][x], map->rot[y - 1][x + 1], fdf);
//						if (y != map->rows - 1)
//							line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x + 1], fdf);
					}
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x],
										   fdf);
				}
			}
		}
		else
		{
			x = map->cols;
			while (--x >= 0)
			{
				y = map->rows;
				while (--y >= 0)
				{
					if (x != map->cols - 1)
					{
						line_clip_and_draw(map->rot[y][x], map->rot[y][x + 1],
										   fdf);
//						if (y != 0)
//							line_clip_and_draw(map->rot[y][x], map->rot[y - 1][x + 1], fdf);
//						if (y != map->rows - 1)
//							line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x + 1], fdf);
					}
					if (y != map->rows - 1)
						line_clip_and_draw(map->rot[y][x], map->rot[y + 1][x],
										   fdf);
				}
			}
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

int		key_hook(int kcode, void *data)
{
	t_fdf			*fdf;
	int 			i, j;

	static int vx = 0, vy = 0, vz = 0;


	int deg = 2;

	fdf = (t_fdf*)data;

//	fdf->param->rx = 0;
//	fdf->param->ry = 0;
//	fdf->param->rz = 0;
//	fdf->param->s_all = 1;

//	if (kcode == 89 || kcode == 92)
//		fdf->param->rx = kcode == 89 ? -deg : deg;
//	else if (kcode == 86 || kcode == 88)
//		fdf->param->ry = kcode == 86 ? -deg : deg;
//	else if (kcode == 83 || kcode == 85)
//		fdf->param->rz = kcode == 83 ? -deg : deg;
//	else if (kcode == 123 || kcode == 124)
//		fdf->param->tx += kcode == 123 ? -10 : 10;
//	else if (kcode == 125 || kcode == 126)
//		fdf->param->ty += kcode == 125 ? 10 : -10;
//
//	if (kcode == 27 || kcode == 24)
//		fdf->param->s_all = kcode == 27 ? 0.9 : 1.1;

	if (kcode == 89 || kcode == 92)
		fdf->param->rx += kcode == 89 ? -deg : deg;
	else if (kcode == 86 || kcode == 88)
		fdf->param->ry += kcode == 86 ? -deg : deg;
	else if (kcode == 83 || kcode == 85)
		fdf->param->rz += kcode == 83 ? -deg : deg;
	else if (kcode == 123 || kcode == 124)
		fdf->param->tx += kcode == 123 ? -5 : 5;
	else if (kcode == 125 || kcode == 126)
		fdf->param->ty += kcode == 125 ? 5 : -5;
	else if (kcode == 78 || kcode == 69)
		fdf->param->tz += kcode == 78 ? -5 : 5;
	else if (kcode == 27 || kcode == 24)
		fdf->param->s_all += kcode == 27 ? -0.5 : 0.5;

	else if (kcode == 0 || kcode == 2)
		vx += kcode == 0 ? -5 : 5;
	else if(kcode == 1 || kcode == 13)
		vy += kcode == 1 ? -5 : 5;
	else if(kcode == 3 || kcode == 15)
		vz += kcode == 3 ? -5 : 5;



	//new *****

	double mtx_glob[4][4];
	double tmp[4][4];
	double tmp2[4][4];

//	init_mas_local(fdf->mas, fdf->map);

	matrix_identity(mtx_glob);

	tr_translate(mtx_glob, -(fdf->map->cols - 1) / 2, -(fdf->map->rows - 1) / 2, 0);

	tr_scale(mtx_glob, fdf->param->s_all, fdf->param->s_all, fdf->param->s_all);
	tr_rotate(mtx_glob, fdf->param->rx, fdf->param->ry, fdf->param->rz);
	tr_translate(mtx_glob, fdf->w_size.x / 2,
			fdf->w_size.y / 2, 0);
	tr_translate(mtx_glob, fdf->param->tx, fdf->param->ty,
			fdf->param->tz);


	mult_local_by_glob_mtx(fdf->mas, fdf->map, mtx_glob);

	get_corners(fdf, mtx_glob);


//	fill_poligons(fdf);

//	i = -1;
//	while (++i < fdf->pol_count)
//		polygon_draw(&fdf->poligon[i], fdf);


//	while (++i < fdf->map->rows)
//	{
//		int j = -1;
//		while (++j < fdf->map->cols)
//		{
//			ft_printf("%f  ", fdf->mas[i][j].world.z);
//		}
//		ft_printf("\n");
//	}
//	ft_printf("\n");



//	tr_translate(mtx_glob, -0, -0, -20);
//	tr_translate(mtx_glob, -fdf->w_size.x / 2,
//				 -fdf->w_size.y / 2, 0);
//
//	mult_local_by_glob_mtx_for_local(fdf->mas, fdf->map, mtx_glob);





//	matrix_identity(mtx_glob);



//	tr_translate(mtx_glob, vx, vy, vz);
//	tr_rotate(mtx_glob, -fdf->param->rx, -fdf->param->ry, -fdf->param->rz);
//	tr_scale(mtx_glob, -fdf->param->s_all, -fdf->param->s_all, -fdf->param->s_all);

//	mult_world_by_glob_mtx(fdf->mas, fdf->map, mtx_glob);




//	i = -1;
//	while (++i < fdf->map->rows)
//	{
//		j = -1;
//		while (++j < fdf->map->cols)
//		{
//			ft_printf("(%.f, %.f)  ", fdf->mas[i][j].local.x, fdf->mas[i][j].local.y);
//		}
//		ft_printf("\n");
//	}

	rotate(fdf->map, fdf);


	//end new *****

//	fdf->param->tx = -((fdf->map->cols - 1) * (fdf->param->s_all)) / 2;
//	fdf->param->ty = -((fdf->map->rows - 1) * (fdf->param->s_all)) / 2;
//
//	init_matrixes(fdf->matrixes, fdf->param);
//
//	fdf->matrixes->base = mult_matrixes(fdf->matrixes->one, fdf->matrixes->translate, 0);
//
//	fdf->matrixes->base = mult_matrixes(fdf->matrixes->base,
//											fdf->matrixes->rot_x, 0);
//	fdf->matrixes->base = mult_matrixes(fdf->matrixes->base,
//											fdf->matrixes->rot_y, 1);
//	fdf->matrixes->base = mult_matrixes(fdf->matrixes->base,
//											fdf->matrixes->rot_z, 1);
////
//	fdf->param->tx += ((fdf->map->cols - 1) * (fdf->param->s_all)) / 2;
//	fdf->param->ty += ((fdf->map->rows - 1) * (fdf->param->s_all)) / 2;
//
//	fdf->param->tx += fdf->w_size.x / 2.0;
//	fdf->param->ty += fdf->w_size.y / 2.0;
////
////
////
//	init_translate(fdf->matrixes, fdf->param);
//	fdf->matrixes->base = mult_matrixes(fdf->matrixes->base, fdf->matrixes->translate, 1);
//
//	rotate(fdf->map, fdf);
//
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
//	draw_map(fdf, fdf->map);
	draw_map2(fdf, fdf->map);
//
//	t_point origin;
//	t_point x;
//	t_point y;
//	t_point z;
//
//	origin.x = fdf->res_coord_sys[0].x;
//	origin.y = fdf->res_coord_sys[0].y;
//
//	x.x = fdf->res_coord_sys[1].x;
//	x.y = fdf->res_coord_sys[1].y;
//
//	y.x = fdf->res_coord_sys[2].x;
//	y.y = fdf->res_coord_sys[2].y;
//
//	z.x = fdf->res_coord_sys[3].x;
//	z.y = fdf->res_coord_sys[3].y;



	put_pixel(fdf, fdf->w_size.x / 2, fdf->w_size.y / 2, 0xff0000);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	ft_bzero(fdf->img, 8000 * fdf->w_size.y);

//	draw_line(origin, x, fdf, 0xff0000);
//	draw_line(origin, y, fdf, 0x00ff00);
//	draw_line(origin, z, fdf, 0x0000ff);

	return (0);
}

//int main()
//{
//	t_fdf	fdf;
////
//	fdf.map = (t_map*)ft_memalloc(sizeof(t_map));
//	read_fdf_map("mars.fdf", fdf.map);
//
//	int i = -1;
////	while (++i < fdf.map->rows)
////	{
////		int j = -1;
////		while (++j < fdf.map->cols)
////			ft_printf("%i ", fdf.map->bas[i][j].y);
////		ft_printf("\n");
////	}
//
//
//
////
//	fdf.matrixes = (t_matrixes*)ft_memalloc(sizeof(t_matrixes));
//	fdf.param = (t_transform_p*)ft_memalloc(sizeof(t_transform_p));
//
//	first_init_matrixes(fdf.matrixes);
//	init_base(fdf.matrixes, fdf.param);
//
//	fdf.param->s_all = 1;
//
//
//	fdf.map->rot = get_copy_base_map(fdf.map);
////
//
////
//	fdf.w_size.x = 2000;
//	fdf.w_size.y = 1200;
////
//	fdf.mlx_ptr = mlx_init();
//	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.w_size.x,
//			fdf.w_size.y, "mlx 42");
////	draw_map(&fdf, fdf.map);
////	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);
////
////
////	mlx_loop(fdf.mlx_ptr);
//
//	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, fdf.w_size.x, fdf.w_size.y);
//
//	char *img;
//
//	int bits_per_pixel;
//	int size_line;
//	int endian;
//
//	img = mlx_get_data_addr (fdf.img_ptr, &bits_per_pixel, &size_line, &endian);
//
//
//	int **frame = (int**)ft_memalloc(sizeof(int*) * fdf.w_size.y);
//
////	int i = -1;
//	i = -1;
//	while (++i < fdf.w_size.y)
//		frame[i] = (img + (size_line * i));
//
//	fdf.frame = frame;
//	fdf.img = img;
//
//	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);
//
//
//	mlx_loop(fdf.mlx_ptr);
//
//
//	return (0);
//}




int main()
{
	t_fdf	fdf;

	fdf.coord_sys[0].x = 0;
	fdf.coord_sys[0].y = 0;
	fdf.coord_sys[0].z = 0;

	fdf.coord_sys[1].x = 100;
	fdf.coord_sys[1].y = 0;
	fdf.coord_sys[1].z = 0;

	fdf.coord_sys[2].x = 0;
	fdf.coord_sys[2].y = 100;
	fdf.coord_sys[2].z = 0;

	fdf.coord_sys[3].x = 0;
	fdf.coord_sys[3].y = 0;
	fdf.coord_sys[3].z = 100;

	fdf.map = (t_map*)ft_memalloc(sizeof(t_map));
//	read_fdf_map("test_maps/42.fdf", fdf.map);
	read_fdf_map("t2.fdf", fdf.map);
//	read_fdf_map("elem-fract.fdf", fdf.map);

	int i;

	fdf.param = (t_transform_p*)ft_memalloc(sizeof(t_transform_p));

	fdf.param->s_all = 0;


	fdf.map->rot = get_copy_base_map(fdf.map);

	fdf.w_size.x = 2000;
	fdf.w_size.y = 1200;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.w_size.x,
								 fdf.w_size.y, "mlx 42");

	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, fdf.w_size.x, fdf.w_size.y);

	char *img;

	int bits_per_pixel;
	int size_line;
	int endian;

	img = mlx_get_data_addr (fdf.img_ptr, &bits_per_pixel, &size_line, &endian);

	int **frame = (int**)ft_memalloc(sizeof(int*) * fdf.w_size.y);

//	int i = -1;
	i = -1;
	while (++i < fdf.w_size.y)
		frame[i] = (img + (size_line * i));

	fdf.frame = frame;
	fdf.img = img;

	fdf.mas = (t_vertex**)ft_memalloc(sizeof(t_vertex*) * fdf.map->rows);
	i = -1;
	while (++i < fdf.map->rows)
		fdf.mas[i] = (t_vertex *) ft_memalloc(sizeof(t_vertex) * fdf.map->cols);



	init_mas_local(fdf.mas, fdf.map);

//	double mtx_glob[4][4];
//
//	matrix_identity(mtx_glob);

//	tr_translate(mtx_glob, -(fdf.map->cols - 1) / 2, -(fdf.map->rows - 1) / 2, 0);
//	tr_scale(mtx_glob, 1, 1, 1);

//	mult_local_by_glob_mtx_for_local(fdf.mas, fdf.map, mtx_glob);





//	i = -1;
//	while (++i < fdf.map->rows)
//	{
//		int j = -1;
//		while (++j < fdf.map->cols)
//		{
//			mas[i][j].local.x = 10;
//			ft_printf("(%f, %f)  ", mas[i][j].local.x, mas[i][j].local.y);
//		}
//		ft_printf("\n");
//	}
//	fdf.pol_count = (fdf.w_size.x - 1) * (fdf.w_size.y - 1);
//	fdf.poligon = (t_poligon_2d*)ft_memalloc(sizeof(t_poligon_2d) * fdf.pol_count);


	mlx_hook(fdf.win_ptr, 2, 0, key_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);

	return (0);
}



// 359 degrees = 6,26573 radian
// 1   degrees = 0,0174533 rad





























