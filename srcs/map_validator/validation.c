#include <fcntl.h>
#include "fdf.h"
#include "libft.h"

static int		get_file_descriptor(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error. The file is not exist!\n");
	if ((read(fd, 0, 0)) == -1)
		ft_error(" Error. You tried open directory! Error!\n");
	return (fd);
}

static int		get_mas_len(char **mas)
{
	int		i;

	i = 0;
	while (*mas++)
		i++;
	return (i);
}

static void		get_z_and_color(t_point *point, char *str, t_map *map)
{
	char	**tmp;
	int		mas_len;

	tmp = ft_strsplit(str, ',');
	mas_len = get_mas_len(tmp);
	if (mas_len > 2)
		ft_error("Format error!\n");
	point->z = ft_get_number(tmp[0]);
	if (point->z < map->min_z)
		map->min_z = point->z;
	if (point->z > map->max_z)
		map->max_z = point->z;
	if (mas_len != 1)
	{
		point->color = ft_get_number(tmp[1]);
		map->color = 1;
	}
	del_list_content(tmp, 0);
}

static t_point	**get_map(t_list *list, t_map *map)
{
	t_point	**mas;
	int		i;
	int		j;
	char	**tmp;

	if (map->rows == 1 && map->cols == 0)
		ft_error("No data input!\n");
	if (!(mas = (t_point**)ft_memalloc(sizeof(t_point*) * map->rows)))
		ft_error("Memory allocation error!\n");
	i = -1;
	while (++i < map->rows)
	{
		if (!(mas[i] = (t_point*)ft_memalloc(sizeof(t_point) * map->cols)))
			ft_error("Memory allocation error!\n");
		j = -1;
		tmp = (char**)list->content;
		while (++j < map->cols)
		{
			get_z_and_color(&mas[i][j], tmp[j], map);
			mas[i][j].y = i;
			mas[i][j].x = j;
		}
		list = list->next;
	}
	return (mas);
}

void	read_fdf_map(char *file, t_map *map)
{
	char	*line;
	char	**mas;
	t_list	*list;
	int		fd;

	fd = get_file_descriptor(file);
	list = NULL;
	get_next_line(fd, &line);
	mas = ft_strsplitf(line, is_delimiter);
	map->cols = get_mas_len(mas);
	ft_lstadd_end(&list, ft_lstnew(mas, 0));
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		mas = ft_strsplitf(line, is_delimiter);
		if (map->cols != get_mas_len(mas))
			ft_error("Found wrong line length. Exiting.\n");
		ft_lstadd_end(&list, ft_lstnew(mas, 0));
		free(line);
	}
	free(line);
	close(fd);
	map->rows = ft_list_size(list);
	map->bas = get_map(list, map);
	ft_lstdel(&list, del_list_content);
}