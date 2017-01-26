/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 01:25:36 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/26 05:45:32 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_size		calc_point(int x, int y, int z, t_opt opt)
{
	t_size	origin;

	if (opt.perspect)
	{
		origin.x = (opt.ct * x - y * opt.ctt) * opt.s
		+ 500 + (opt.vert * 50);
		origin.y = (-z + (opt.ct / 2) * x + (opt.ctt / 2) * y) * opt.s
		+ 500 + (opt.vert * 50);
	}
	else
	{
		origin.x = ((x + (z * opt.ct))) * opt.s
		+ 500 + (opt.horiz * 50);
		origin.y = ((y + (z * (opt.ct / 2)))) * opt.s
		+ 500 + (opt.horiz * 50);
	}
	return (origin);
}
