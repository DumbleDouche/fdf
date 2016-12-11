/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:35:55 by rchoquer          #+#    #+#             */
/*   Updated: 2016/12/11 11:41:35 by rchoquer         ###   ########.fr       */
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

t_info			*setup(t_info *info)
{
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		ft_exit(ERROR);
	if ((info->token = mlx_init())
	&& (info->window = mlx_new_window(info->token, 500, 500, "Mon FDF")))
		return info;
	exit (-1);
	return (info);
}

int				main(int argc, char **argv)
{
	t_info		*info;
	int			*array;

	// if (argc != 2)
	// 	ft_exit(BADARG, info);
	// (void)argc;
	// (void)argv;
	
	info = setup(info);
	draw(info);
	free(info);
	return (0);
}