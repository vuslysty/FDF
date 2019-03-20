/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:42:07 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/16 17:43:14 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_GET_NEXT_LINE_H
# define PRINTF_GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <unistd.h>

int					get_next_line(const int fd, char **line);

typedef struct		s_fdlst
{
	char			*data;
	int				fd;
	struct s_fdlst	*next;
}					t_fdlst;

#endif
