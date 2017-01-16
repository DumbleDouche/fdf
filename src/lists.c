/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 02:47:48 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/16 22:14:48 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"

void		lst_append(t_node **node, size_t x, size_t y, long z)
{
	t_node *iter;

	iter = *node;
	while (iter)
		iter = iter->next;
	iter = (t_node)malloc(sizeof(t_node));
	iter->x = x;
	iter->y = y;
	iter->z = z;
	iter->next = NULL;
}