/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 02:32:18 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/26 06:13:55 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/fdf.h"

static void		recreate_img(t_env *env)
{
	t_env	e;

	e = *env;
	e.img = mlx_new_image(e.mlx, 1000, 1000);
	e.imgaddr = mlx_get_data_addr(e.win, &e.bpp, &e.sl, &e.endian);
	draw(e, e.head);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	// mlx_string_put(e.mlx, e.win, 0, 0, 0xffffff, "Salope des quartiers");
}

static void		move_pos(int key, t_env *e)
{
	if (key == 126)
		--(e->opt.vert);
	if (key == 125)
		++(e->opt.vert);
	if (key == 124)
		--(e->opt.horiz);
	if (key == 123)
		++(e->opt.horiz);
	recreate_img(&(*e));
}

int				hook_key(int keycode, t_env *e)
{
	if (keycode == 53 || keycode == 17)
		ft_exit(PROPER);
	if (keycode >= 123 && keycode <= 126)
		move_pos(keycode, &(*e));
	// ft_putstr("Unknown Key\n");
	printf("key: %d\n", keycode);
	return (1);
}