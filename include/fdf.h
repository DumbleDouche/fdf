/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 07:06:37 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/11 17:53:05 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/include/libft.h"
#include <stdlib.h>

#ifndef FDF_H
#define FDF_H

typedef enum		STATUS
{
	EXIT = 0,
	ERROR = -1,
	BADARG = 2,
}					STATUS;

typedef struct		s_size
{
	size_t			x;
	size_t			y;
}					t_size;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_size			size;
}					t_env;

int					draw(t_env e, t_size size);
int					ft_exit(STATUS current);
int					print_key(int keycode, void *e);
t_env				setup(void);


#endif