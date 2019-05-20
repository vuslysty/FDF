#include "libft.h"

int		is_delimiter(char c)
{
	if (c == ' ' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	del_list_content(void *content, size_t tmp)
{
	char	**mas;

	if (tmp)
		;
	mas = (char**)content;
	while(*mas)
		free(*mas++);
	free((char**)content);
}