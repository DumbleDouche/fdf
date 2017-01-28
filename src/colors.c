/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 04:42:58 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/28 02:51:05 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		colors(t_env *e, int key)
{
	if (key == 16 && R < 237)
		R += 20;
	else if (key == 32 && G < 237)
		G += 20;
	else if (key == 34 && B < 237)
		B += 20;
	else if (key == 4 && R > 19)
		R -= 20;
	else if (key == 38 && G > 19)
		G -= 20;
	else if (key == 40 && B > 19)
		B -= 20;
	e->opt.color.full = (R * 65536) + (G * 256) + B;
	recreate_img(*e);
}
