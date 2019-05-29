#include "fdf.h"

t_point		**get_copy_base_map(t_map *map)
{
	t_point	**copy;
	int		i;
	int 	j;

	copy = (t_point**)ft_memalloc(sizeof(t_point*) * map->rows);
	i = -1;
	while (++i < map->rows)
		copy[i] = (t_point*)ft_memalloc(sizeof(t_point) * map->cols);
	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			copy[i][j].x = map->bas[i][j].x;
			copy[i][j].y = map->bas[i][j].y;
			copy[i][j].z = map->bas[i][j].z;
			copy[i][j].color = map->bas[i][j].color;
		}
	}
	return (copy);
}