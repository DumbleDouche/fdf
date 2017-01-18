/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:35:55 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/18 03:22:52 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_exit(char *error)
{
	ft_putendl(error);
	exit(1);
}

t_env			setup(char *name)
{
	t_env		e;

	e.size.x = 800;
	e.size.y = 800;
	if (!(e.mlx = mlx_init())
	|| !(e.win = mlx_new_window(e.mlx, e.size.x, e.size.y, name))
	|| !(e.img = mlx_new_image(e.mlx, e.size.x, e.size.y)))
		ft_exit(ERROR);
	return (e);
}

int				main(int ac, char **av)
{
	t_env		e;
	int			*array;
	t_size		size;
	t_point		*points;
	int			fd;

	if (ac != 2)
		ft_exit(BADARG);
	size.x = 10;
	size.y = 10;
	array = 0;
	if (0 >= (fd = open(av[1], O_RDONLY)))
		ft_exit(FILE);
	points = store(fd);
	close(fd);
	print_lst(points);
	e = setup(av[1]);
	draw(e, size, points);
	return (0);
}
