#include "fdf.h"

void	init_mas_local(struct s_vertex **mas, t_map *map)
{
	int 	i;
	int 	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			mas[i][j].local.x = map->bas[i][j].x;
			mas[i][j].local.y = map->bas[i][j].y;
			mas[i][j].local.z = map->bas[i][j].z;
		}
	}
}


void	mult_local_by_glob_mtx(struct s_vertex **mas, t_map *map, double global[4][4])
{
	int 	i;
	int 	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
			vec_mult_matrix(&mas[i][j].local, global, &mas[i][j].world);
	}
}

//void	mult_world_by_glob_mtx(struct s_vertex **mas, t_map *map, double global[4][4])
//{
//	int 	i;
//	int 	j;
//
//	i = -1;
//	while (++i < map->rows)
//	{
//		j = -1;
//		while (++j < map->cols)
//			vec_mult_matrix(&mas[i][j].world, global, &mas[i][j].aligned);
//	}
//}

//void	mult_local_by_glob_mtx_for_local(struct s_vertex **mas, t_map *map, double global[4][4])
//{
//	int 	i;
//	int 	j;
//	t_3d	tmp;
//
//	i = -1;
//	while (++i < map->rows)
//	{
//		j = -1;
//		while (++j < map->cols)
//		{
//			vec_mult_matrix(&mas[i][j].local, global, &tmp);
//			mas[i][j].local.x = tmp.x;
//			mas[i][j].local.y = tmp.y;
//			mas[i][j].local.z = tmp.z;
//		}
//	}
//}