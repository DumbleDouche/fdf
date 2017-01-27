/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 04:42:58 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/27 05:15:42 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		colors(t_env *e, int key)
{
	if (key == 16 && e->opt.color < 16777215 - 65535)
		e->opt.color += 0x1ffff;
	else if (key == 32 && e->opt.color < 255 - 5)
		e->opt.color += 0x1ff;
	else if (key == 34 && e->opt.color < 0xffffff)
		e->opt.color += 2;
	else if (key == 4 && e->opt.color > 0xffff)
		e->opt.color -= 0x1ffff;
	else if (key == 38 && e->opt.color > 0xff)
		e->opt.color -= 0x1ff;
	else if (key == 40 && e->opt.color > 0)
		e->opt.color -= 2;
	recreate_img(*e);
}
