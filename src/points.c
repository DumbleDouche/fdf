/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 01:25:36 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/27 04:25:04 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_coord		calc_point(int x, int y, int z, t_opt opt)
{
	t_coord	origin;

	if (opt.perspect)
	{
		origin.x = (opt.ct * x - y * opt.ctt) * opt.s
		+ 550 + (opt.vert * 10);
		origin.y = (-z + (opt.ct / 2) * x + (opt.ctt / 2) * y) * opt.s
		+ 400 + (opt.horiz * 10);
	}
	else
	{
		origin.x = ((x + (-z * opt.ct))) * opt.s
		+ 200 + (opt.vert * 10);
		origin.y = ((y + (-z * (opt.ct / 2)))) * opt.s
		+ 200 + (opt.horiz * 10);
	}
	return (origin);
}
