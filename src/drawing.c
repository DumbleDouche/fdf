/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:36:02 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/26 06:12:53 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/fdf.h"

void		pixel_put(t_env e, int x, int y, int color)
{
	unsigned int	*addr;

	addr = (unsigned int*)(e.imgaddr);
	addr[y * 1 +x * 1] = mlx_get_color_value(e.mlx, color);
}

void		drawline(int x0, int y0, int x1, int y1, t_env e)
{
	t_draw	o;

	o.dx = abs(x1 - x0);
	o.sx = x0 < x1 ? 1 : -1;
	o.dy = abs(y1 - y0);
	o.sy = y0 < y1 ? 1 : -1;
	o.err = (o.dx > o.dy ? o.dx : -o.dy) / 2;
	printf("while %p\n", e.img);
	while (42)
	{
		pixel_put(e, x0, y0, 0x9aff9a);
		if (x0 == x1 && y0 == y1)
			break ;
		o.e2 = o.err;
		if (o.e2 > -o.dx)
		{
			o.err -= o.dy;
			x0 += o.sx;
		}
		if (o.e2 < o.dy)
		{
			o.err += o.dx;
			y0 += o.sy;
		}
	}
}

void			draw(t_env e, t_point *iter)
{
	t_point		*ln;
	t_size		origin;
	t_size		end;

	ln = NULL;
	while (iter)
	{
		ln = nxtln(iter);
		if (iter->next)
		{
			origin = calc_point(X, Y, Z, e.opt);
			end = calc_point(NX, NY, NZ, e.opt);
			Y == NY ? drawline(origin.x, origin.y, end.x, end.y, e) : 0;
			end = calc_point(LX, LY, LZ, e.opt);
			drawline(origin.x, origin.y, end.x, end.y, e);
		}
		iter = iter->next;
	}
}

int					core(t_env *e, t_point *iter)
{
	printf("before %p\n", e->img);
	draw(*e, iter);
	mlx_key_hook(e->win, hook_key, &(*e));
	printf("afterafter %p\n", e->img);	
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_loop(e->mlx);
	return (1);
}