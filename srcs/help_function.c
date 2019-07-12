/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:54:00 by vuslysty          #+#    #+#             */
/*   Updated: 2019/07/12 16:54:02 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

static void	exit_instructions(t_fdf *fdf)
{
	static char	*help[] = {
			"EXIT:",
			"Key  ESC"
	};

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1800, 700, 0x00FF00, help[0]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1800, 720, 0x00FF00, help[1]);
}

static void	translate_instructions(t_fdf *fdf)
{
	static char	*help[3] = {
			"TRANSLATE:",
			"Key  LEFT | RIGHT",
			"Key   UP  | DOWN",
	};

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1800, 40, 0x00FF00, help[0]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1800, 60, 0x00FF00, help[1]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1800, 80, 0x00FF00, help[2]);
}

void		get_help(t_fdf *fdf)
{
	rotate_instructions(fdf);
	translate_instructions(fdf);
	fps_instructions(fdf);
	scale_instructions(fdf);
	projection_instructions(fdf);
	color_instructions(fdf);
	exit_instructions(fdf);
}
