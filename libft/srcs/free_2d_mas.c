#include "libft.h"

void	free_2d_char_d(char ***mas)
{
	char	***tmp;

	tmp = mas;
	while (**mas != NULL)
	{
		free(**mas);
		(*mas)++;
	}
	free(*tmp);
}