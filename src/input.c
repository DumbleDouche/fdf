/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 01:26:42 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/16 22:14:44 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../include/fdf.h"

t_point		*store(int fd)
{
	char	**coord;
	char	*line;
	size_t	y;
	size_t	x;

	line = NULL;
	x = 0;
	y = 1;
	while (y)
	{
		if (!get_next_line(fd, &line))
			break ;
		coord = ft_split(line, ' ');
		ft_strdel(&line);
		while (coord[x])
		{
			lst_append(x, y, coord[x]);
			++x;
		}
		ft_strdelpp()
		++y;
	}
}