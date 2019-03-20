/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:16:03 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/16 17:41:24 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static void		delete_unused_fd(t_fdlst **begin, t_fdlst *lst)
{
	t_fdlst			*tmp;

	tmp = *begin;
	if (*begin == lst)
	{
		tmp = tmp->next;
		free((*begin)->data);
		free(*begin);
		*begin = tmp;
	}
	else
	{
		while (tmp->next != lst)
			tmp = tmp->next;
		tmp->next = tmp->next->next;
		free(lst->data);
		free(lst);
	}
}

static int		check_endline(t_fdlst *list, char **line)
{
	int				i;
	int				len;
	char			*tmp;

	i = -1;
	len = ft_strlen(*line);
	while (list->data[++i] != '\0')
	{
		if (list->data[i] == '\n')
		{
			tmp = *line;
			*line = ft_memjoin(*line, len, list->data, i);
			free(tmp);
			(*line)[len + i] = '\0';
			ft_strcpy(list->data, list->data + i + 1);
			return (1);
		}
	}
	tmp = *line;
	*line = ft_memjoin(*line, len, list->data, i);
	(*line)[i + len] = '\0';
	free(tmp);
	return (0);
}

static t_fdlst	*get_right_list(const int fd, t_fdlst **list)
{
	t_fdlst			*tmp;

	tmp = *list;
	if (tmp == NULL)
	{
		*list = (t_fdlst*)malloc(sizeof(t_fdlst));
		(*list)->fd = fd;
		(*list)->data = ft_memalloc(BUFF_SIZE + 1);
		(*list)->next = NULL;
		tmp = *list;
	}
	else
	{
		while (tmp != NULL && tmp->fd != fd)
			tmp = tmp->next;
		if (tmp == NULL)
		{
			tmp = (t_fdlst*)malloc(sizeof(t_fdlst));
			tmp->fd = fd;
			tmp->data = ft_memalloc(BUFF_SIZE + 1);
			tmp->next = *list;
			*list = tmp;
		}
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_fdlst	*list;
	t_fdlst			*tmp;
	int				rd;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strdup("");
	tmp = get_right_list(fd, &list);
	if (check_endline(tmp, line))
		return (1);
	while ((rd = read(tmp->fd, tmp->data, BUFF_SIZE)) && rd != -1)
	{
		tmp->data[rd] = '\0';
		if (check_endline(tmp, line))
			return (1);
	}
	delete_unused_fd(&list, tmp);
	if (**line != 0)
		return (1);
	return (rd == -1 ? -1 : 0);
}
