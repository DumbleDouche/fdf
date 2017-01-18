/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 01:26:42 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/18 02:13:40 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../includes/fdf.h"

t_point		*store(int fd)
{
	char	**coord;
	char	*line;
	t_point	*node;
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	line = NULL;
	node = NULL;
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
		ft_memdelpp((void***)&coord);
		++y;
	}
	return (node);
}
