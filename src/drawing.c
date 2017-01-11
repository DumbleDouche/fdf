/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:36:02 by rchoquer          #+#    #+#             */
/*   Updated: 2016/12/11 19:55:49 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


#include "../include/fdf.h"

int				draw_line(t_env e, t_size size)
{
	size_t		i;
	t_size		middle;

	i = 0;
	middle.x = (e.size.x / 2) - (size.x * 10);
	middle.y = (e.size.y / 2) - (size.y * 10);
	while (i < size.x * 10)
	{
		mlx_pixel_put(e.mlx, e.win, middle.x + i, middle.y, 0xFFFFFF);
		i++;
	}
	i = 0;
	while (i < size.y * 10)
	{
		mlx_pixel_put(e.mlx, e.win, middle.x, middle.y + i, 0xFFFFFF);
		i++;
	}
	return (1);
}

int				draw(t_env e, t_size size)
{
	void		*param;

	param = &e;
	mlx_key_hook(e.win, print_key, param);
	draw_line(e, size);
	mlx_loop(e.mlx);
	return (1);
}

int				print_key(int keycode, void *e)
{
	(void)e;
	if (keycode == 53 || keycode == 17)
		exit (1);
	printf("Unknown Key\n");
	return (1);
}
