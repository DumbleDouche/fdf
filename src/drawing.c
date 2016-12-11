/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:36:02 by rchoquer          #+#    #+#             */
/*   Updated: 2016/12/11 11:42:33 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


#include "../include/fdf.h"

int				draw(t_info *info)
{
	void		*param;

	param = &info;
	mlx_key_hook(info->window, print_key, param);
	mlx_loop(info->token);
	return (1);
}

int				print_key(int keycode, void *info)
{
	(void)info;
	if (keycode == 53)
		exit (1);
	printf("Unknown Key\n");
	return (1);
}
