/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 06:24:20 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/21 04:35:17 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static t_fd			*getfd(int fd, t_fd **fdlst)
{
	t_fd	*node;
	t_fd	*last;

	node = *fdlst;
	last = *fdlst;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		last = node;
		node = node->next;
	}
	node = (t_fd*)malloc(sizeof(t_fd));
	node->fd = fd;
	node->left = NULL;
	node->next = NULL;
	if (*fdlst)
		last->next = node;
	else
		*fdlst = node;
	return (node);
}

static int			left(char **left, char **line)
{
	char *temp;

	if (!(temp = ft_strchr(*left, '\n')))
	{
		*line = ft_strdup(*left);
		free(*left);
		*left = NULL;
		return (0);
	}
	*temp = '\0';
	*line = ft_strdup(*left);
	temp = ft_strdup(temp + 1);
	free(*left);
	*left = temp;
	return (1);
}

static int			store(char **start, char **occur, char **line, char **left)
{
	char	*temp;

	**occur = '\0';
	temp = ft_strjoin(*line, *start);
	ft_strdel(line);
	*line = temp;
	ft_strdel(left);
	*left = ft_strdup(*occur + 1);
	ft_strdel(start);
	return (1);
}

static int			readfile(int fd, char **line, char **left)
{
	char		*buf;
	char		*temp;
	int			byte;

	buf = ft_strnew(BUFF_SIZE);
	while ((byte = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[byte] = '\0';
		if ((temp = ft_strchr(buf, '\n')) && store(&buf, &temp, line, left))
			return (1);
		temp = ft_strjoin(*line, buf);
		free(*line);
		*line = temp;
	}
	free(buf);
	if (byte < 0)
		return (-1);
	if (!byte && !**line)
		return (0);
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static t_fd		*start = NULL;
	t_fd			*node;

	if (!line || fd < 0)
		return (-1);
	node = getfd(fd, &start);
	*line = malloc(sizeof(char) * 1);
	**line = 0;
	if (node->left && left(&(node->left), line))
		return (1);
	return (readfile(fd, line, &(node->left)));
}
