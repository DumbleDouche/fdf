/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:35:55 by rchoquer          #+#    #+#             */
/*   Updated: 2016/12/11 18:18:17 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				ft_exit(STATUS current)
{
	if (current == ERROR)
	{
		ft_putendl("Something went wrong");
		exit (ERROR);
	}
	else if (current == BADARG)
	{
		ft_putendl("usage: ./fdf file");
		exit (ERROR);
	}
	return (0);
}

t_env			setup(void)
{
	t_env		e;

	e.size.x = 800;
	e.size.y = 800;
	if (!(e.mlx = mlx_init())
	|| !(e.win = mlx_new_window(e.mlx, e.size.x, e.size.y, "Mon FDF")))
		exit (-1);
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
	e = setup();
	draw(e, size);
	return (0);
}