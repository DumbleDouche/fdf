/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:35:55 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/27 04:33:57 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <unistd.h>

void			ft_exit(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}

static t_env	setup(char *name)
{
	t_env		e;

	e.size.x = 1000;
	e.size.y = 1000;
	if (!(e.mlx = mlx_init())
	|| !(e.win = mlx_new_window(e.mlx, e.size.x, e.size.y, name)))
		ft_exit(ERROR);
	e.opt.perspect = 1;
	e.opt.ct = 0.50;
	e.opt.ctt = 0.50;
	e.opt.tmp = 0;
	e.opt.ct_p = 0.25;
	e.opt.tmp = 0;
	e.opt.vert = 0;
	e.opt.horiz = 0;
	e.opt.s = 20;
	e.opt.height = 1;
	e.opt.color = 0x9aff9a;
	return (e);
}

int				main(int ac, char **av)
{
	t_env		e;
	t_point		*head;
	int			fd;
	int			*array;

	if (ac != 2)
		ft_exit(BADARG);
	array = 0;
	if (0 >= (fd = open(av[1], O_RDONLY)))
		ft_exit(FILE);
	head = store(fd, &e);
	close(fd);
	e = setup(av[1]);
	e.head = head;
	core(&e, head);
	mlx_destroy_window(e.mlx, e.win);
	return (0);
}
