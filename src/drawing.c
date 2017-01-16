/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:36:02 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/16 22:14:35 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../includes/fdf.h"

// int				draw_line(t_env e, t_size size)
// {
// 	size_t		i;
// 	t_size		middle;

// 	i = 0;
// 	middle.x = (e.size.x / 2) - (size.x * 10);
// 	middle.y = (e.size.y / 2) - (size.y * 10);
// 	while (i < size.x * 10)
// 	{
// 		mlx_pixel_put(e.mlx, e.win, middle.x + i, middle.y, 0xFFFFFF);
// 		++i;
// 	}
// 	i = 0;
// 	while (i < size.y * 10)
// 	{
// 		mlx_pixel_put(e.mlx, e.win, middle.x, middle.y + i, 0xFFFFFF);
// 		++i;
// 	}
// 	return (1);
// }

void		draw_line(int x0, int y0, int x1, int y1, t_env e) {
 
  int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = (dx > dy ? dx : -dy) / 2, e2;
 
  for(;;){
    mlx_pixel_put(e.mlx, e.win, x0,y0, 0xFFFFFF);
    if (x0 == x1 && y0 == y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

int				draw(t_env e, t_size size)
{
	void		*param;

	param = &e;
	(void)size;
	mlx_key_hook(e.win, print_key, param);
	draw_line(500, 500, 600, 400, e);
	draw_line(600, 400, 200, 400, e);
	mlx_loop(e.mlx);
	return (1);
}

int				print_key(int keycode, void *e)
{
	(void)e;
	if (keycode == 53 || keycode == 17)
		ft_exit(PROPER);
	printf("Unknown Key\n");
	return (1);
}
