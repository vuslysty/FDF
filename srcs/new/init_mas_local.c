#include "fdf.h"

void	init_mas_local(t_vertex **mas, t_map *map)
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