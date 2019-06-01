#include "fdf.h"

void		can_mult_matrix(t_matrix *m1, t_matrix *m2)
{
	if (m1->cols != m2->rows)
		ft_error("Matrices cannot be multiplicated.\n");
}

void	delete_matrix(t_matrix *mtx)
{
	int			i;

	i = -1;
	while (++i < mtx->rows)
		free(mtx->mtx[i]);
	free(mtx->mtx);
	free(mtx);
}

t_matrix	*mult_matrixes(t_matrix *m1, t_matrix *m2, int opt)
{
	int			i;
	int 		j;
	int 		k;
	t_matrix	*new_matrix;

	can_mult_matrix(m1, m2);
	new_matrix = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	new_matrix->rows = m1->rows;
	new_matrix->cols = m2->cols;
	new_matrix->mtx = (double**)ft_memalloc(sizeof(double*) * m1->rows);
	i = -1;
	while (++i < m1->rows)
	{
		new_matrix->mtx[i] = (double*)ft_memalloc(sizeof(double) * m2->cols);
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				new_matrix->mtx[i][j] += m1->mtx[i][k] * m2->mtx[k][j];
		}
	}

	if (opt == 1)
		delete_matrix(m1);

	return (new_matrix);
}

void		*mult_matrixes_arg(t_matrix *m1, t_matrix *m2, t_matrix *m3)
{
	int			i;
	int 		j;
	int 		k;

	can_mult_matrix(m1, m2);
	i = -1;
	while (++i < m1->rows)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				m3->mtx[i][j] += m1->mtx[i][k] * m2->mtx[k][j];
		}
	}
}
