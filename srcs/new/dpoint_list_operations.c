#include "fdf.h"

void	add_new_line(t_dline **list, t_point *a, t_point *b)
{
	t_dline	*tmp;

	tmp = (t_dline*)ft_memalloc(sizeof(struct s_dline));
	tmp->a.x = a->x;
	tmp->a.y = a->y;
	tmp->b.x = b->x;
	tmp->b.y = b->y;
	if (*list != NULL)
		*list = tmp;
	else
	{
		tmp->next = *list;

	}
}