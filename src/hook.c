/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 02:32:18 by rchoquer          #+#    #+#             */
/*   Updated: 2017/02/04 07:50:55 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		move_pos(int key, t_env *e)
{
	if (key == 0)
		--(e->opt.vert);
	else if (key == 2)
		++(e->opt.vert);
	else if (key == 13)
		--(e->opt.horiz);
	else if (key == 1)
		++(e->opt.horiz);
	recreate_img(*e);
}

static void		move_space(int key, t_env *e)
{
	if (key == 126 && e->opt.perspect)
		(e->opt.ctt) -= 0.01;
	else if (key == 125 && e->opt.perspect)
		(e->opt.ctt += 0.01);
	else if (key == 124)
		(e->opt.ct) += 0.01;
	else if (key == 123)
		(e->opt.ct) -= 0.01;
	else if (key == 31 && e->opt.s > 0)
		--(e->opt.s);
	else if (key == 35)
		++(e->opt.s);
	recreate_img(*e);
}

static void		reset_opt(t_env *e)
{
	e->opt.perspect = 1;
	e->opt.ct = 0.50;
	e->opt.ctt = 0.50;
	e->opt.tmp = 0;
	e->opt.ct_p = 0.50;
	e->opt.vert = 0;
	e->opt.horiz = 0;
	e->opt.s = 20;
	e->opt.height = 1;
	e->opt.color.r = 125;
	e->opt.color.g = 125;
	e->opt.color.b = 125;
	e->opt.color.full = 0x7d7d7d;
	recreate_img(*e);
}

int				mouse_hook(int button, int x, int y, t_env *e)
{
	(void)button;
	mlx_pixel_put(e->mlx, e->win, x, y, e->opt.color.full);
	return (0);
}

int				hook_key(int keycode, t_env *e)
{
	if (keycode == 53)
		ft_exit(PROPER, 1);
	else if ((keycode >= 123 && keycode <= 126)
	|| keycode == 31 || keycode == 35)
		move_space(keycode, &(*e));
	else if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		move_pos(keycode, e);
	else if (keycode == 15)
		reset_opt(e);
	else if (keycode == 32 || keycode == 34 || keycode == 16 || keycode == 4
	|| keycode == 38 || keycode == 40)
		colors(&(*e), keycode);
	else if (keycode == 8)
	{
		e->opt.tmp = e->opt.ct;
		e->opt.ct = e->opt.ct_p;
		e->opt.ct_p = e->opt.tmp;
		e->opt.perspect = !e->opt.perspect;
		recreate_img(*e);
	}
	return (1);
}
