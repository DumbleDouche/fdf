/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:36:02 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/18 05:05:11 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../includes/fdf.h"

void			drawline(int x0, int y0, int x1, int y1, t_env e)
{
	int		dx = abs(x1 - x0);
	int		sx = x0 < x1 ? 1 : -1;
	int		dy = abs(y1 - y0);
	int		sy = y0 < y1 ? 1 : -1;
	int		err = (dx > dy ? dx : -dy) / 2;
	int		e2;

	while (1)
	{
		mlx_pixel_put(e.mlx, e.win, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

int				draw(t_env e, t_size size, t_point *points)
{
	void		*param;
	t_point		*iter;
	t_point		*ln;

	param = &e;
	(void)size;
	iter = points;
	ln = NULL;
	while (iter)
	{
		ln = nxtln(iter);
		if (iter->next)
		{
			Y == NY ?
			drawline(CX(X, Y, Z), CY(X, Y, Z), CX(NX, Y, NZ), CY(NX, NY, NZ)
			, e) : 0;
			drawline(CX(X, Y, Z), CY(X, Y, Z), CX(LX, LY, LZ), CY(LX, LY, LZ)
			, e);
		}
		iter = iter->next;
	}
	mlx_key_hook(e.win, print_key, param);
	mlx_loop(e.mlx);
	return (1);
}

int				print_key(int keycode)
{
	if (keycode == 53 || keycode == 17)
		ft_exit(PROPER);
	ft_putstr("Unknown Key\n");
	return (1);
}
