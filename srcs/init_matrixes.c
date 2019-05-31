#include "fdf.h"

void		init_matrixes(t_matrixes *matrixes, t_transform_p *param)
{
	init_rot_x(matrixes, param);
	init_rot_y(matrixes, param);
	init_rot_z(matrixes, param);
	init_translate(matrixes, param);
	init_partical_scale(matrixes, param);
	init_scale(matrixes, param);

	init_one(matrixes, param);
}