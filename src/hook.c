/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 02:32:18 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/26 07:33:17 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		recreate_img(t_env e)
{
	mlx_clear_window(e.mlx, e.win);
	draw(e, e.head);
}

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
	if (key == 126)
		(e->opt.ctt) -= 0.01;
	else if (key == 125)
		(e->opt.ctt += 0.01);
	else if (key == 124)
		(e->opt.ct) += 0.01;
	else if (key == 123)
		(e->opt.ct) -= 0.01;
	else if (key == 31)
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
	e->opt.vert = 0;
	e->opt.horiz = 0;
	e->opt.s = 20;
	e->opt.height = 1;
	recreate_img(*e);
}

int				hook_key(int keycode, t_env *e)
{
	if (keycode == 53)
		ft_exit(PROPER);
	else if ((keycode >= 123 && keycode <= 126)
	|| keycode == 31 || keycode == 35)
		move_space(keycode, &(*e));
	else if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		move_pos(keycode, e);
	else if (keycode == 15)
		reset_opt(e);
	else if (keycode == 8)
	{
		e->opt.perspect = !e->opt.perspect;
		recreate_img(*e);
	}
	return (1);
}
