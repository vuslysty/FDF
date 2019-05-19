#include "fdf.h"
#include "validator.h"

int		get_mas_len(char **mas)
{
	int		i;

	i = 0;
	while (*mas++)
		i++;
	return (i);
}

int		**get_map(t_list *list, t_map *map)
{
	int		**mas;
	int		i;
	int		j;
	char	**tmp;

	if (!(mas = (int**)ft_memalloc(sizeof(int*) * map->rows)))
		ft_error("Memory allocation error!\n");
	i = -1;
	while (++i < map->rows)
	{
		if (!(mas[i] = (int*)ft_memalloc(sizeof(int) * map->cols)))
		ft_error("Memory allocation error!\n");
		j = -1;
		tmp = *(char***)list->content;
		while (++j < map->cols)
			mas[i][j] = ft_get_number(tmp[j]);
		// можливо тут чиститиму сонтент ліста
		list = list->next;
	}
	return (mas);
}

void	read_fdf_map(int fd, t_map *map)
{
	char	*line;
	char	**mas;
	t_list	*list;

	list = NULL;
	get_next_line(fd, &line);
	mas = ft_strsplitf(line, is_delimiter);
	map->cols = get_mas_len(mas);
	ft_lstadd_end(&list, ft_lstnew(&mas, map->cols));
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		mas = ft_strsplitf(line, is_delimiter);
		if (map->cols != get_mas_len(mas))
			ft_error("Found wrong line length. Exiting.\n");
		ft_lstadd_end(&list, ft_lstnew(&mas, map->cols));
	}
	map->rows = ft_list_size(list);
	map->map = get_map(list, map);
}