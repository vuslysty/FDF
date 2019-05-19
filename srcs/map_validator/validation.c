#include <fcntl.h>
#include "fdf.h"
#include "libft.h"
#include "validator.h"

int		get_file_descriptor(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error. The file is not exist!\n");
	if ((read(fd, 0, 0)) == -1)
		ft_error(" Error. You tried open directory! Error!\n");
	return (fd);
}

void	map_validation(char *file, t_map *map)
{
	int		fd;

	fd = get_file_descriptor(file);
	read_fdf_map(fd, map);
}
