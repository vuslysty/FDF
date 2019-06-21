#include "fdf.h"

void	add_new_line(t_dline **list, t_point *a, t_point *b)
{
	t_dline	*tmp;

	tmp = (t_dline*)ft_memalloc(sizeof(struct s_dline));
	tmp->a = *a;
	tmp->b = *b;
	if (*list != NULL)
		tmp->next = *list;
	*list = tmp;
}

void	del_dline_list(t_dline **list)
{
	t_dline	*tmp;

	if (*list != NULL)
	{
		while (*list != NULL)
		{
			tmp = *list;
			*list = (*list)->next;
			free(tmp);
		}
	}
}