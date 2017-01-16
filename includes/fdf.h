/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 07:06:37 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/16 01:55:44 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
// #include "../mlx/mlx.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

#ifndef FDF_H
#define FDF_H

#define	ERROR  "Something went wrong"
#define BADARG "usage: ./fdf file"
#define PROPER "./fdf ended properly"

typedef struct		s_size
{
	size_t			x;
	size_t			y;
}					t_size;

typedef struct		s_node
{
	size_t			x;
	size_t			y;
	long			z;
	struct s_node	*next;
}					t_node;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_size			size;
}					t_env;

int					draw(t_env e, t_size size);
void				ft_exit(char *error);
int					print_key(int keycode, void *e);
t_env				setup(char *name);


#endif