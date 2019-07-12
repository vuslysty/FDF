/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:54:24 by vuslysty          #+#    #+#             */
/*   Updated: 2019/07/12 16:54:25 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	fps_instructions(t_fdf *fdf)
{
	static char	*help[2] = {
			"FPS (ON/OFF):",
			"Key F"
	};

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 400, 0x00FF00, help[0]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 420, 0x00FF00, help[1]);
}

void	color_instructions(t_fdf *fdf)
{
	static char	*help[] = {
			"COLOR:",
			"Key F1  -  OFF",
			"Key F2  -  ON"
	};

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 700, 0x00FF00, help[0]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 720, 0x00FF00, help[1]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 740, 0x00FF00, help[2]);
}

void	projection_instructions(t_fdf *fdf)
{
	static char	*help[] = {
			"PROJECTIONS",
			"Orthographic  -  O",
			"Isometric  -  I",
			"Dimetric  -  D",
			"Trimetric  -  T",
			"Cabinet  -  K",
			"Cavalier  -  C"
	};

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 950, 1000, 0x00FF00, help[0]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 1050, 0x00FF00, help[1]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 350, 1050, 0x00FF00, help[2]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 700, 1050, 0x00FF00, help[3]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1050, 1050, 0x00FF00, help[4]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1400, 1050, 0x00FF00, help[5]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1820, 1050, 0x00FF00, help[6]);
}

void	rotate_instructions(t_fdf *fdf)
{
	static char	*help[4] = {
			"ROTATE:",
			"x-asix  -  7 | 9",
			"y-asix  -  4 | 6",
			"z-asix  -  1 | 3"
	};

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 40, 0x00FF00, help[0]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 60, 0x00FF00, help[1]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 80, 0x00FF00, help[2]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 100, 0x00FF00, help[3]);
}

void	scale_instructions(t_fdf *fdf)
{
	static char	*help[3] = {
			"SCALE:",
			"Zoom in  |  +",
			"Zoom out |  -"
	};

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1800, 400, 0x00FF00, help[0]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1800, 420, 0x00FF00, help[1]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1800, 440, 0x00FF00, help[2]);
}
