/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mas_local.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:58:10 by vuslysty          #+#    #+#             */
/*   Updated: 2019/07/12 16:58:12 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mas_local(struct s_vertex **mas, t_map *map)
{
	int	i;
	int	j;

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

void	mult_local_by_glob_mtx(struct s_vertex **mas, t_map *map,
			double global[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
			vec_mult_matrix(&mas[i][j].local, global, &mas[i][j].world);
	}
}
