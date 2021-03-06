/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 02:47:48 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/27 03:30:38 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fdf.h"

void		lst_append(t_point **node, size_t x, size_t y, long z)
{
	t_point *iter;
	t_point	*last;

	iter = *node;
	last = iter;
	while (iter)
	{
		last = iter;
		iter = iter->next;
	}
	iter = (t_point*)malloc(sizeof(t_point));
	iter->x = x;
	iter->y = y;
	iter->z = z;
	iter->next = NULL;
	if (*node)
		last->next = iter;
	else
		*node = iter;
}

t_point		*nxtln(t_point *node)
{
	t_point		*iter;

	iter = node;
	iter = iter->next ? iter->next : iter;
	while (iter && iter->x != node->x)
		iter = iter->next;
	return (iter ? iter : node);
}
