/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 02:47:48 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/17 00:32:40 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


#include <stdlib.h>
#include "../includes/fdf.h"

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
		printf("yes\n");
	}
	iter = (t_point*)malloc(sizeof(t_point));
	iter->x = x;
	iter->y = y;
	iter->z = z;
	last->next = iter;
	iter->next = NULL;
}

int			print_lst(t_point *node)
{
	size_t	i;
	t_point	*iter;

	i = 0;
	iter = node;
	// printf("here: %ld\n", node->z);
	while (iter)
	{
		ft_putnbr(iter->z);
		ft_putchar(' ');
		++i;
		iter = iter->next;
	}
	return (i);
}
