/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:35:55 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/16 22:14:51 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>

void			ft_exit(char *error)
{
	ft_putendl(error);
	exit (1);
}

t_env			setup(char *name)
{
	t_env		e;

	e.size.x = 800;
	e.size.y = 800;
	if (!(e.mlx = mlx_init())
	|| !(e.win = mlx_new_window(e.mlx, e.size.x, e.size.y, name))
	|| !(e.img = mlx_new_image(e.mlx, e.size.x, e.size.y)))
		ft_exit (ERROR);
	return (e);
}

int				main(int argc, char **argv)
{
	t_env		e;
	int			*array;
	t_size		size;

	// if (argc != 2)
	// 	ft_exit(BADARG, e);
	(void)argc;
	(void)argv;
	size.x = 10;
	size.y = 10;
	array = 0;
	e = setup(argv[1]);
	draw(e, size);
	return (0);
}