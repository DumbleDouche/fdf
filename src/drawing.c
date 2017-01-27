/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:36:02 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/27 04:51:09 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			drawline(t_coord origin, t_coord end, t_env e)
{
	t_draw	o;

	o.dx = labs(end.x - origin.x);
	o.sx = origin.x < end.x ? 1 : -1;
	o.dy = labs(end.y - origin.y);
	o.sy = origin.y < end.y ? 1 : -1;
	o.err = (o.dx > o.dy ? o.dx : -o.dy) / 2;
	while (42)
	{
		mlx_pixel_put(e.mlx, e.win, origin.x, origin.y, e.opt.color);
		if (origin.x == end.x && origin.y == end.y)
			break ;
		o.e2 = o.err;
		if (o.e2 > -o.dx)
		{
			o.err -= o.dy;
			origin.x += o.sx;
		}
		if (o.e2 < o.dy)
		{
			o.err += o.dx;
			origin.y += o.sy;
		}
	}
}

void			draw(t_env e, t_point *iter)
{
	t_point		*ln;
	t_coord		origin;
	t_coord		end;

	ln = NULL;
	while (iter)
	{
		ln = nxtln(iter);
		if (iter->next)
		{
			origin = calc_point(X, Y, Z, e.opt);
			end = calc_point(NX, NY, NZ, e.opt);
			Y == NY ? drawline(origin, end, e) : 0;
			end = calc_point(LX, LY, LZ, e.opt);
			drawline(origin, end, e);
		}
		iter = iter->next;
	}
}

int				core(t_env *e, t_point *iter)
{
	draw(*e, iter);
	mlx_key_hook(e->win, hook_key, &(*e));
	mlx_loop(e->mlx);
	return (1);
}
