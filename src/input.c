/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 01:26:42 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/26 05:08:30 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../include/fdf.h"

static void	initval(size_t *x, size_t *y, char **line, t_point **node)
{
	*x = 0;
	*y = 0;
	*line = NULL;
	*node = NULL;
}

static void	max_x(size_t x, t_env *e)
{
	if (e->x < x)
		e->x = x;
}

t_point		*store(int fd, t_env *e)
{
	size_t	x;
	size_t	y;
	char	*line;
	char	**coord;
	t_point	*node;

	initval(&x, &y, &line, &node);
	while (get_next_line(fd, &line))
	{
		coord = ft_strsplit(line, ' ');
		ft_strdel(&line);
		x = 0;
		while (coord[x])
		{
			lst_append(&node, x, y, ft_atoi(coord[x]));
			++x;
		}
		max_x(x, e);
		ft_memdelpp((void***)&coord);
		++y;
	}
	e->y = y;
	return (node);
}
