#include "fdf.h"

t_matrix	*init_matrix(int rows, int cols)
{
	int 		i;
	t_matrix	*matrix;

	matrix = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	matrix->mtx = (double**)ft_memalloc(sizeof(double*) * rows);
	i = -1;
	while (++i < rows)
		matrix->mtx[i] = (double*)ft_memalloc(sizeof(double) * cols);
	matrix->cols = cols;
	matrix->rows = rows;
	return (matrix);
}

void	first_init_matrixes(t_matrixes *matrixes)
{
	matrixes->rot_x = init_matrix(4, 4);
	matrixes->rot_y = init_matrix(4, 4);
	matrixes->rot_z = init_matrix(4, 4);
	matrixes->translate = init_matrix(4, 4);
	matrixes->scale = init_matrix(4, 4);
	matrixes->partica_scale = init_matrix(4, 4);
	matrixes->shift = init_matrix(4, 4);
	matrixes->result_matrix = init_matrix(4, 4);
	matrixes->result_point = init_matrix(1, 4);

	matrixes->one = init_matrix(4, 4);
}