
#ifndef FDF_VALIDATOR_H
# define FDF_VALIDATOR_H
# include "fdf.h"

int		is_delimiter(char c);
void	read_fdf_map(int fd, t_map *map);
void	map_validation(char *file, t_map *map);

#endif
